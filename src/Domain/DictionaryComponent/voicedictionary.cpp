#include <QDebug>
#include <QString>
#include "voicedictionary.h"
#include "src/iphrase.h"
#include "src/ialias.h"
#include "phonemes.h"

using namespace waltz::agent::DictionaryComponent;

VoiceDictionary::VoiceDictionary()
{
}

VoiceDictionary::VoiceDictionary(
        const Syllables& aSyllables,
        const Fragments& aFragments)
    : mSyllables_(aSyllables)
    , mFragments_(aFragments)
{
}

VoiceDictionary::VoiceDictionary(const VoiceDictionary& aOther)
    : mSyllables_(aOther.mSyllables_)
    , mFragments_(aOther.mFragments_)
{

}

VoiceDictionary& VoiceDictionary::operator=(const VoiceDictionary& aOther)
{
    mSyllables_ = aOther.mSyllables_;
    mFragments_ = aOther.mFragments_;
    return (*this);
}

waltz::agent::FragmentList VoiceDictionary::phraseToFragmentList(const waltz::agent::IPhrase* aPhrase)
{
    if (aPhrase == 0)
    {
        qWarning("Phrase pointer is null.");
        return FragmentList();
    }
    return phonemesSentenceToFragmentList(
                aliasVectorToPhonemesSentence(aPhrase->aliases()));
}

JoinedPhonemesSentence VoiceDictionary::phraseToJoinedPhonemesSentence(const waltz::agent::IPhrase *aPhrase)
{
    if (aPhrase == 0)
    {
        qWarning("Phrase pointer is null.");
        return JoinedPhonemesSentence("");
    }
    return aliasVectorToPhonemesSentence(aPhrase->aliases()).join();
}

PhonemesSentence VoiceDictionary::aliasVectorToPhonemesSentence(std::vector<waltz::agent::IAlias*> aAliasVector)
{
    PhonemesSentence phonemesSentence;
    for(waltz::agent::IAlias* alias: aAliasVector)
    {
        phonemesSentence.append((mSyllables_.find(Alias(QString(alias->value().c_str()))).phonemes()));
    }
    return phonemesSentence;
}

waltz::agent::FragmentList VoiceDictionary::phonemesSentenceToFragmentList(const PhonemesSentence& aPhonemesSentence)
{
    return mFragments_.phonemeSentenceToFragmentList(aPhonemesSentence);
}

