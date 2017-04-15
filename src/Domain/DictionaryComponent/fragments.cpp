#include <QDebug>
#include "fragments.h"
#include "src/fragmentdata.h"
#include "joinedphonemessentence.h"

using namespace waltz::agent::DictionaryComponent;

Fragments::Fragments()
    :mFragments_()
{
}

Fragments::Fragments(const Fragments& aOther)
    :mFragments_(aOther.mFragments_)
{
}

Fragments& Fragments::operator=(const Fragments& aOther)
{
    mFragments_ = aOther.mFragments_;
    return (*this);
}

void Fragments::append(const Fragment &aFragment)
{
    mFragments_.append(aFragment);
}

waltz::agent::FragmentList Fragments::phonemeSentenceToFragmentList(const PhonemesSentence& aPhonemesSentnece) const
{
    FragmentList fragmentList;
    JoinedPhonemesSentence joinedPhonemesSentence = aPhonemesSentnece.join();

    while(joinedPhonemesSentence.size() > 0)
    {
        int phonemesSize = 0;
        SamePhonemeFragmentSets samePhonemeFragmentSets =
                assembleSamePhonemeFragmentSets(joinedPhonemesSentence, phonemesSize);
        if (samePhonemeFragmentSets.isEmpty())
        {
            joinedPhonemesSentence = joinedPhonemesSentence.deleteLeftSide(1);
            continue;
        }
        fragmentList.appendSamePhonemeFragmentSets(samePhonemeFragmentSets);
        joinedPhonemesSentence = joinedPhonemesSentence.deleteLeftSide(phonemesSize);
    }

    return fragmentList;
}

waltz::agent::SamePhonemeFragmentSets Fragments::assembleSamePhonemeFragmentSets(const JoinedPhonemesSentence& aJoinedPhonemesSentence,
                                                                                 int& aPhonemesSize) const
{
    aPhonemesSize = 0;
    waltz::agent::SamePhonemeFragmentSets samePhonemeFragmentSets;

    foreach(Fragment fragment, mFragments_)
    {
        if(! fragment.matchPhonemsAtHead(aJoinedPhonemesSentence))
        {
            continue;
        }

        int fragmentPhonemesLength = fragment.phonemes().length();
        aPhonemesSize = (aPhonemesSize < fragmentPhonemesLength) ? fragmentPhonemesLength : aPhonemesSize;
        FragmentData fragmentData(fragment);
        samePhonemeFragmentSets.append(fragmentData);
    }
    return samePhonemeFragmentSets;
}
