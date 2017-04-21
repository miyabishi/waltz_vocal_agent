#include "length.h"
#include "Domain/DictionaryComponent/milliseconds.h"

using namespace waltz::agent;

Length::Length(const waltz::agent::DictionaryComponent::MilliSeconds& aMilliSeconds,
               const int    aSampleRate,
               const int    aSampleSize)
 : mMilliSeconds_(new waltz::agent::DictionaryComponent::MilliSeconds(aMilliSeconds))
 , mSampleRate_(aSampleRate)
 , mSampleSize_(aSampleSize)
{
}

Length::Length(const Length& aOther)
    : mMilliSeconds_(aOther.mMilliSeconds_)
    , mSampleRate_(aOther.mSampleRate_)
    , mSampleSize_(aOther.mSampleSize_)
{

}

Length& Length::operator=(const Length& aOther)
{
    mMilliSeconds_ = aOther.mMilliSeconds_;
    mSampleRate_ = aOther.mSampleRate_;
    mSampleSize_ = aOther.mSampleSize_;
    return (*this);
}

double Length::asMilliSeconds() const
{
    return mMilliSeconds_->value();
}

int Length::asArrayLength() const
{
    return mMilliSeconds_->toArrayLength(mSampleRate_);
}

int Length::asBytePosition() const
{
    return mMilliSeconds_->toBitPosition(mSampleRate_, mSampleSize_);
}
