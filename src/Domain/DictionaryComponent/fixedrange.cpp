#include "fixedrange.h"
#include <qdebug.h>

using namespace waltz::agent::DictionaryComponent;

FixedRange::FixedRange()
    : mLength_(0)
    , mOverlap_(0)
    , mPreceding_(0)
{
}

FixedRange::FixedRange(MilliSeconds aLength,
                       MilliSeconds aOverlap,
                       MilliSeconds aPreceding)
    : mLength_(aLength)
    , mOverlap_(aOverlap)
    , mPreceding_(aPreceding)
{
}

FixedRange::FixedRange(const FixedRange& aOther)
    : mLength_(aOther.mLength_)
    , mOverlap_(aOther.mOverlap_)
    , mPreceding_(aOther.mPreceding_)
{
}

FixedRange& FixedRange::operator=(const FixedRange& aOther)
{
    mLength_ = aOther.mLength_;
    mOverlap_ = aOther.mOverlap_;
    mPreceding_ = aOther.mPreceding_;
    return (*this);
}

MilliSeconds FixedRange::length() const
{
    return mLength_;
}

MilliSeconds FixedRange::overlap() const
{
    return mOverlap_;
}

MilliSeconds FixedRange::preceding() const
{
    return mPreceding_;
}
