#ifndef WAVEFORMDATA_H
#define WAVEFORMDATA_H

#include <vector>

namespace waltz
{
    namespace agent
    {

        class WaveformData
        {
        public:
            WaveformData(int aSampleRate,
                         short int aSampleSize,
                         const std::vector<int>& aWavform);
            WaveformData(const WaveformData& aOther);
            WaveformData& operator=(const WaveformData& aOther);

            int sampleRate() const;
            short int sampleSize() const;

        private:
            int              mSampleRate_;
            short int        mSampleSize_;
            std::vector<int> mWaveform_;
        };

    } // namespace agent
} // namespace waltz

#endif // WAVEFORMDATA_H
