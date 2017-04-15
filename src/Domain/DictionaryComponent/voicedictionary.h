#ifndef VOICEDICTIONARY_H
#define VOICEDICTIONARY_H

#include <memory>
#include <vector>
#include <QString>
#include "src/fragmentlist.h"
#include "syllables.h"
#include "fragments.h"
#include "phonemessentence.h"

namespace waltz
{
    namespace agent
    {
        class IAlias;
        class IPhrase;
        namespace DictionaryComponent
        {
            class VoiceDictionary
            {
            public:
                VoiceDictionary();
                VoiceDictionary(const Syllables& aSyllables,
                                const Fragments& aFragments);
                VoiceDictionary(const VoiceDictionary& aOther);
                VoiceDictionary& operator=(const VoiceDictionary& aOther);

            public:
                waltz::agent::FragmentList phraseToFragmentList(const waltz::agent::IPhrase* aPhrase);
                JoinedPhonemesSentence phraseToJoinedPhonemesSentence(const waltz::agent::IPhrase* aPhrase);

            private:
                PhonemesSentence aliasVectorToPhonemesSentence(std::vector<waltz::agent::IAlias*> aAliasVector);
                waltz::agent::FragmentList phonemesSentenceToFragmentList(const PhonemesSentence& aPhonemesSentence);

            private:
                Syllables mSyllables_;
                Fragments mFragments_;
            };
        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // VOICEDICTIONARY_H
