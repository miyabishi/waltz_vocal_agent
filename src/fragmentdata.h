#ifndef FRAGMENTDATA_H
#define FRAGMENTDATA_H

#include <memory>
#include <vector>
#include "waltzvocalagent_global.h"

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class Fragment;

        }

        namespace Wave
        {
            class Waveform;
        }

        class Length;
        class WALTZVOCALAGENTSHARED_EXPORT FragmentData
        {
        public:
            explicit FragmentData(const DictionaryComponent::Fragment& aFragment);
            FragmentData(const FragmentData& aOther);
            FragmentData& operator=(const FragmentData& aOther);
            ~FragmentData();

        public:
            std::string phonemes() const;
            std::vector<int> waveform() const;
            char* waveformRawData() const;
            int waveformRawDataSize() const;
            Length length() const;
            Length lengthOfFixedRange() const;
            Length overlap() const;
            Length preceding() const;
            int sampleRate() const;
            int sampleSize() const;
            std::string comment() const;
            std::shared_ptr<double> toDoubleArray() const;

        private:
            std::shared_ptr<DictionaryComponent::Fragment> mFragment_;
            std::shared_ptr<Wave::Waveform>                mWaveform_;
        };
    } // namespace agent
} // namespace waltz

#endif // FRAGMENTDATA_H
