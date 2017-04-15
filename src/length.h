#ifndef LENGTH_H
#define LENGTH_H

#include <memory>
#include "waltzvocalagent_global.h"

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class MilliSeconds;
        }
        class WALTZVOCALAGENTSHARED_EXPORT Length
        {
        public:
            Length(const waltz::agent::DictionaryComponent::MilliSeconds& aMilliSeconds,
                   const int    aSampleRate);
            Length(const Length& aOther);
            Length& operator=(const Length& aOther);

        public:
            double asMilliSeconds() const;
            int asFrames() const;

        private:
            std::shared_ptr<waltz::agent::DictionaryComponent::MilliSeconds> mMilliSeconds_;
            int    mSampleRate_;
        };
    } // namespace agent
} // namespace waltz

#endif // LENGTH_H
