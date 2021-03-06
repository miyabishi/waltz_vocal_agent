#include <QBuffer>
#include "waveform.h"

using namespace waltz::agent::Wave;

Waveform::Waveform()
{
}

Waveform::Waveform(const QByteArray& aRawData,
                   const int   aSampleRate,
                   const int   aSampleSize)
 : mRawData_(new QByteArray(aRawData))
 , mSampleRate_(aSampleRate)
 , mSampleSize_(aSampleSize)
{
}

Waveform::Waveform(const Waveform& aOther)
    : mRawData_(aOther.mRawData_)
    , mSampleRate_(aOther.mSampleRate_)
    , mSampleSize_(aOther.mSampleSize_)
{
}

Waveform& Waveform::operator=(const Waveform& aOther)
{
    mRawData_    = aOther.mRawData_;
    mSampleRate_ = aOther.mSampleRate_;
    mSampleSize_ = aOther.mSampleSize_;

    return (* this);
}

std::shared_ptr<Waveform> Waveform::trim(const int aStart,
                                         const int aLength)
{
    QBuffer buff(mRawData_.data());
    buff.open(QIODevice::ReadOnly);
    buff.seek(aStart);
    int readSize = aLength;
    if(aLength > (mRawData_->size() - aStart))
    {
        readSize = (mRawData_->size() - aStart - 1);
    }

    std::shared_ptr<Waveform> waveform(
                new Waveform(buff.read(readSize),
                             mSampleRate_,
                             mSampleSize_));
    return waveform;
}

QList<int> Waveform::waveformValues() const
{
    QList<int> waveformValues;
    QBuffer buffer(mRawData_.data());
    buffer.open(QIODevice::ReadOnly);
    buffer.seek(0);

    while(! buffer.atEnd())
    {
        int byte = mSampleSize_ / 8;
        char buff[byte];
        int  value;
        if (buffer.read(buff, byte) == byte)
        {
            memcpy(&value, buff, byte);
            waveformValues.append(value);
        }
    }
    return waveformValues;
}

QSharedPointer<QByteArray> Waveform::rawData() const
{
    return mRawData_;
}

int Waveform::sampleRate() const
{
    return mSampleRate_;
}

int Waveform::sampleSize() const
{
    return mSampleSize_;
}

void Waveform::setSampleRate(int aSampleRate)
{
    mSampleRate_ = aSampleRate;
}

void Waveform::setSampleSize(int aSampleSize)
{
    mSampleSize_ = aSampleSize;
}
