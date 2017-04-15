#ifndef WAVFILE_H
#define WAVFILE_H

#include <QFile>
#include <QAudioFormat>
#include "wavfileheaderstructure.h"
#include "src/Domain/DictionaryComponent/milliseconds.h"
#include "waveform.h"

namespace waltz
{
    namespace agent
    {
        namespace Wave
        {
            class WavFile : public QFile
            {
            public:
                WavFile(QObject *aParent = 0);

            public:
                using QFile::open;
                bool open(const QString& aFileName);
                qint64 headerLength() const;
                WaveformPointer trim(waltz::agent::DictionaryComponent::MilliSeconds aStartTime,
                                     waltz::agent::DictionaryComponent::MilliSeconds aLength);

            private:
                bool isSupportedFormat();
                bool readHeader();
                bool readHeaderStructure(WavFileHeaderStructure* aHeader);
                bool throwAwayExtendData(const WavFileHeaderStructure& aHeader);
                bool readDataHeader(DATAHeader* dataHeader);
                bool isRIFF(const WavFileHeaderStructure& aHeader) const;
                bool isRIFX(const WavFileHeaderStructure& aHeader) const;
                bool isCorrectHeader(const WavFileHeaderStructure& aHeader) const;
                bool isCorrectRiffId(const WavFileHeaderStructure& aHeader) const;
                bool isCorrectRiffType(const WavFileHeaderStructure& aHeader) const;
                bool isCorrectWaveId(const WavFileHeaderStructure& aHeader) const;
                bool isCorrectAudioFormat(const WavFileHeaderStructure& aHeader) const;
                void establishFormat(const WavFileHeaderStructure& aHeader);
                void setByteOrderToFormat(const WavFileHeaderStructure& aHeader);
                void setSampleTypeToFormat(const WavFileHeaderStructure& aHeader);

            private:
                QAudioFormat    mFileFormat_;
                qint64          mHeaderLength_;
                WaveformPointer mWaveform_;

            };
        } // namespace Wave
    } // namespace agent
} // namespace waltz

#endif // WAVFILE_H
