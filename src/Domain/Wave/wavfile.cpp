#include <QtDebug>
#include <qendian.h>
#include <QAudioDecoder>
#include <QDir>

#include "wavfile.h"

using namespace waltz::agent::Wave;

WavFile::WavFile(QObject* aParent)
    :QFile(aParent)
    , mHeaderLength_(0)
{
}

bool WavFile::open(const QString &aFileName)
{
    close();
    if (!exists(aFileName))
    {
        qWarning() << "file not found";
        return false;
    }

    setFileName(aFileName);
    if (! QFile::open(QIODevice::ReadOnly))
    {
        qWarning() << "failed to open";
        return false;
    }
    if (! readHeader())
    {
        qWarning() << "failed to read header";
        return false;
    }
    return true;
}


WaveformPointer WavFile::trim(waltz::agent::DictionaryComponent::MilliSeconds aStartTime,
                              waltz::agent::DictionaryComponent::MilliSeconds aLength)
{
    return mWaveform_->trim(
                aStartTime.toBitPosition(mFileFormat_.sampleRate(),
                                         mFileFormat_.sampleSize()),
                aLength.toBitPosition(mFileFormat_.sampleRate(),
                                      mFileFormat_.sampleSize()));
}

qint64 WavFile::headerLength() const
{
    return mHeaderLength_;
}

bool WavFile::readHeader()
{
    seek(0);
    WavFileHeaderStructure header;
    mHeaderLength_ = 0;
    if (! readHeaderStructure(&header))
    {
        qWarning() << "failed to read header structure";
        return false;
    }
    if (! isCorrectHeader(header))
    {
        qWarning() << "it is not correct header";
        return false;
    }
    if (! throwAwayExtendData(header))
    {
        qWarning() << "failed to throw away extend data.";
        return false;
    }

    DATAHeader dataHeader;
    if (! readDataHeader(&dataHeader))
    {
        qWarning() << "failed to read data header";
        return false;
    }

    establishFormat(header);

    mHeaderLength_ = pos();
    if (!isSupportedFormat())
    {
        qWarning() << "It's not supproted wav file.";
    }

    seek(mHeaderLength_);
    mWaveform_ = WaveformPointer(new Waveform(
                                     readAll(),
                                     mFileFormat_.sampleRate(),
                                     mFileFormat_.sampleSize()));
    return true;
}

bool WavFile::isSupportedFormat()
{
    return (mFileFormat_.channelCount() == 1);
}

void WavFile::establishFormat(const WavFileHeaderStructure& aHeader)
{
    setByteOrderToFormat(aHeader);
    mFileFormat_.setChannelCount(
                qFromLittleEndian<quint16>(aHeader.wave.numChannels));
    mFileFormat_.setCodec("audio/pcm");
    mFileFormat_.setSampleRate(qFromLittleEndian<quint32>(aHeader.wave.sampleRate));
    mFileFormat_.setSampleSize(qFromLittleEndian<quint16>(aHeader.wave.bitsPerSample));

    setSampleTypeToFormat(aHeader);
}

void WavFile::setSampleTypeToFormat(const WavFileHeaderStructure &aHeader)
{
    int bps = qFromBigEndian<quint16>(aHeader.wave.bitsPerSample);
    if (bps == 8)
    {
        mFileFormat_.setSampleType(QAudioFormat::UnSignedInt);
        return;
    }
    mFileFormat_.setSampleType(QAudioFormat::SignedInt);
}

void WavFile::setByteOrderToFormat(const WavFileHeaderStructure& aHeader)
{
    if(isRIFF(aHeader))
    {
        mFileFormat_.setByteOrder(QAudioFormat::LittleEndian);
        return;
    }
    mFileFormat_.setByteOrder(QAudioFormat::BigEndian);
    return;
}

bool WavFile::throwAwayExtendData(const WavFileHeaderStructure& aHeader)
{
    if (qFromLittleEndian<quint32>(aHeader.wave.descriptor.size) <= sizeof(WAVEHeader))
    {
        return true;
    }
    quint16 extraFormatBytes;
    if (peek((char*)&extraFormatBytes, sizeof(quint16)) != sizeof(quint16))
    {
        return false;
    }

    const qint64 throwAwayBytes = sizeof(quint16) + qFromLittleEndian<quint16>(extraFormatBytes);
    if (read(throwAwayBytes).size() != throwAwayBytes)
    {
        return false;
    }
    return true;
}

bool WavFile::readDataHeader(DATAHeader *dataHeader)
{
    return read((char*)dataHeader, sizeof(DATAHeader))
            == sizeof(DATAHeader);
}

bool WavFile::readHeaderStructure(WavFileHeaderStructure* aHeader)
{
    return read(reinterpret_cast<char *>(aHeader), sizeof(WavFileHeaderStructure))
            == sizeof(WavFileHeaderStructure);
}

bool WavFile::isCorrectHeader(const WavFileHeaderStructure& aHeader) const
{
    return isCorrectRiffId(aHeader)
            && isCorrectRiffType(aHeader)
            && isCorrectWaveId(aHeader)
            && isCorrectAudioFormat(aHeader);
}

bool WavFile::isCorrectRiffId(const WavFileHeaderStructure &aHeader) const
{
    return isRIFF(aHeader) || isRIFX(aHeader);
}

bool WavFile::isRIFF(const WavFileHeaderStructure& aHeader) const
{
    return memcmp(&aHeader.riff.descriptor.id, "RIFF", 4) == 0;
}

bool WavFile::isRIFX(const WavFileHeaderStructure& aHeader) const
{
    return memcmp(&aHeader.riff.descriptor.id, "RIFX", 4) == 0;
}

bool WavFile::isCorrectRiffType(const WavFileHeaderStructure &aHeader) const
{
    return memcmp(&aHeader.riff.type, "WAVE", 4) == 0;
}

bool WavFile::isCorrectWaveId(const WavFileHeaderStructure &aHeader) const
{
    return memcmp(&aHeader.wave.descriptor.id, "fmt", 3) == 0;
}

bool WavFile::isCorrectAudioFormat(const WavFileHeaderStructure& aHeader) const
{
    return aHeader.wave.audioFormat == 1
           || aHeader.wave.audioFormat == 0;
}
