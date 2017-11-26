#include "Domain/DictionaryComponent/fragment.h"
#include "samephonemefragmentsets.h"

using namespace waltz::agent;

SamePhonemeFragmentSets::SamePhonemeFragmentSets()
{

}

SamePhonemeFragmentSets::SamePhonemeFragmentSets(const SamePhonemeFragmentSets& aOther)
    : mSamePhonemeFragmentSets_(aOther.mSamePhonemeFragmentSets_)
{
}

SamePhonemeFragmentSets& SamePhonemeFragmentSets::operator=(const SamePhonemeFragmentSets& aOther)
{
    mSamePhonemeFragmentSets_ = aOther.mSamePhonemeFragmentSets_;
    return (*this);
}

void SamePhonemeFragmentSets::append(const FragmentData &aFragmentData)
{
    mSamePhonemeFragmentSets_.append(aFragmentData);
}

bool SamePhonemeFragmentSets::isEmpty() const
{
    return mSamePhonemeFragmentSets_.isEmpty();
}

int SamePhonemeFragmentSets::length() const
{
    return mSamePhonemeFragmentSets_.length();
}

FragmentData SamePhonemeFragmentSets::at(int aPosition) const
{
    if (mSamePhonemeFragmentSets_.length() < aPosition)
    {
        Q_ASSERT("a Position's value is bigger than length.");
        return FragmentData(waltz::agent::DictionaryComponent::Fragment());
    }
    return mSamePhonemeFragmentSets_.at(aPosition);
}
