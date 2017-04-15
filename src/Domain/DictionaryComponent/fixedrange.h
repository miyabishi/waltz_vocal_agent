#ifndef FIXEDRANGE_H
#define FIXEDRANGE_H

#include "milliseconds.h"

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class FixedRange
            {
            public:
                FixedRange();
                FixedRange(MilliSeconds aLength,
                           MilliSeconds aOverlap,
                           MilliSeconds aPreceding);
                FixedRange(const FixedRange& aOther);
                FixedRange& operator=(const FixedRange& aOther);
                MilliSeconds length() const;
                MilliSeconds overlap() const;
                MilliSeconds preceding() const;

            private:
                MilliSeconds mLength_;
                MilliSeconds mOverlap_;
                MilliSeconds mPreceding_;
            };
        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // FIXEDRANGE_H
