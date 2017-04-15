#ifndef FRAGMENTS_H
#define FRAGMENTS_H

#include <QList>
#include "fragment.h"
#include "src/fragmentlist.h"
#include "phonemessentence.h"
#include "src/samephonemefragmentsets.h"
#include "joinedphonemessentence.h"

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class Fragments
            {
            public:
                Fragments();
                Fragments(const Fragments& aOther);
                Fragments& operator=(const Fragments& aOther);

            public:
                void append(const Fragment& aFragment);
                waltz::agent::FragmentList phonemeSentenceToFragmentList(
                        const PhonemesSentence& aPhonemesSentnece) const;

            private:
                waltz::agent::SamePhonemeFragmentSets assembleSamePhonemeFragmentSets(
                                        const JoinedPhonemesSentence& aJoinedPhonemesSentence,
                                        int& aPhonemeSize) const;

            private:
                QList<Fragment> mFragments_;
            };
        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // FRAGMENTS_H
