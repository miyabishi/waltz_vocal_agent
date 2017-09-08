#ifndef WAVEFORM_H
#define WAVEFORM_H

#include<memory>
#include <QList>
#include <QBitArray>
#include <QSharedPointer>

namespace waltz
{
    namespace agent
    {
        namespace Wave
        {
            class Waveform
            {
            public:
                Waveform();
                Waveform(const QByteArray& aRawData,
                         const int aSampleRate,
                         const int aSampleSize);
                Waveform(const Waveform& aOther);
                Waveform& operator=(const Waveform& aOther);

            public:
                std::shared_ptr<Waveform> trim(const int aStart,
                                               const int aLength);
                QList<int> waveformValues() const;
                QSharedPointer<QByteArray> rawData() const;
                int sampleRate() const;
                int sampleSize() const;
                void setSampleRate(int aSampleRate);
                void setSampleSize(int aSampleSize);

            private:
                QSharedPointer<QByteArray> mRawData_;
                int        mSampleRate_;
                int        mSampleSize_;
            };
            typedef std::shared_ptr<Waveform>(WaveformPointer);
        } // namespace Wav
    } // namespace agent
} // namespace waltz

#endif // WAVEFORM_H
