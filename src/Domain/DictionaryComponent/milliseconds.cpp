#include "milliseconds.h"

using namespace waltz::agent::DictionaryComponent;

MilliSeconds::MilliSeconds(const double aValue)
    : mValue_(aValue)
{
}

MilliSeconds::MilliSeconds(const MilliSeconds& aOther)
    : mValue_(aOther.mValue_)
{
}

MilliSeconds& MilliSeconds::operator=(const MilliSeconds& aOther)
{
    mValue_ = aOther.mValue_;
    return (* this);
}

double MilliSeconds::value() const
{
    return mValue_;
}
double MilliSeconds::toSeconds() const
{
    return mValue_ / 1000.0;
}

int MilliSeconds::toArrayLength(int aSampleRate) const
{
    return toSeconds() * aSampleRate;
}

int MilliSeconds::toBitPosition(int aSampleRate, int aSampleSize) const
{
    return toArrayLength(aSampleRate) * aSampleSize / 8;
}
