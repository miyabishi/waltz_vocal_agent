#include <QDebug>
#include "phonemessentence.h"

using namespace waltz::agent::DictionaryComponent;

namespace
{
    const QString PHONEMES_START_POINT = "^";
    const QString PHONEMES_SEPARATOR   = "/";
    const QString PHONEMES_END_POINT   = "$";
}

PhonemesSentence::PhonemesSentence()
{
}

PhonemesSentence::PhonemesSentence(const PhonemesSentence& aOther)
    :mPhonemesSentence_(aOther.mPhonemesSentence_)
{
}

PhonemesSentence& PhonemesSentence::operator=(const PhonemesSentence& aOther)
{
    mPhonemesSentence_ = aOther.mPhonemesSentence_;
    return (*this);
}

void PhonemesSentence::append(Phonemes aPhonemes)
{
    mPhonemesSentence_.append(aPhonemes);
}

JoinedPhonemesSentence PhonemesSentence::join() const
{
    QString joinedString = PHONEMES_START_POINT + PHONEMES_SEPARATOR;
    foreach(Phonemes phonemes, mPhonemesSentence_)
    {
        joinedString += phonemes.value() + PHONEMES_SEPARATOR;
    }
    joinedString += PHONEMES_END_POINT;
    return JoinedPhonemesSentence(joinedString);
}

