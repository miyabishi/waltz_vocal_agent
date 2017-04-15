#include "length.h"
#include "Domain/DictionaryComponent/milliseconds.h"

using namespace waltz::agent;

Length::Length(const waltz::agent::DictionaryComponent::MilliSeconds& aMilliSeconds,
               const int    aSampleRate)
 : mMilliSeconds_(new waltz::agent::DictionaryComponent::MilliSeconds(aMilliSeconds))
 , mSampleRate_(aSampleRate)
{
}

Length::Length(const Length& aOther)
    : mMilliSeconds_(aOther.mMilliSeconds_)
    , mSampleRate_(aOther.mSampleRate_)
{

}

Length& Length::operator=(const Length& aOther)
{
    mMilliSeconds_ = aOther.mMilliSeconds_;
    mSampleRate_ = aOther.mSampleRate_;
    return (*this);
}

double Length::asMilliSeconds() const
{
    return mMilliSeconds_->value();
}

int Length::asFrames() const
{
    return mMilliSeconds_->toFrames(mSampleRate_);
}
