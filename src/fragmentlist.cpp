#include "fragmentlist.h"

using namespace waltz::agent;

FragmentList::FragmentList()
{
}

FragmentList::FragmentList(const FragmentList& aOther)
    :mSamePhonemeFragmentSets_(aOther.mSamePhonemeFragmentSets_)
{
}

FragmentList& FragmentList::operator=(const FragmentList& aOther)
{
    mSamePhonemeFragmentSets_ = aOther.mSamePhonemeFragmentSets_;
    return (*this);
}

void FragmentList::appendSamePhonemeFragmentSets(const SamePhonemeFragmentSets& aSamePhonemFragmentSets)
{
    mSamePhonemeFragmentSets_.append(aSamePhonemFragmentSets);
}

int FragmentList::length() const
{
    return mSamePhonemeFragmentSets_.length();
}

SamePhonemeFragmentSets FragmentList::at(const int aPosition) const
{
    if (mSamePhonemeFragmentSets_.length() < aPosition)
    {
        qWarning("SamePhonemeFragmentSets: a Position's value is bigger than length.");
        return SamePhonemeFragmentSets();
    }
    return mSamePhonemeFragmentSets_.at(aPosition);
}
