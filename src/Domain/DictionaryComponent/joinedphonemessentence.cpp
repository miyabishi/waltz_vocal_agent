#include "joinedphonemessentence.h"

using namespace waltz::agent::DictionaryComponent;

JoinedPhonemesSentence::JoinedPhonemesSentence(const QString& aValue)
 : mValue_(aValue)
{
}

JoinedPhonemesSentence::JoinedPhonemesSentence(const JoinedPhonemesSentence &aOther)
    : mValue_(aOther.mValue_)
{
}

JoinedPhonemesSentence& JoinedPhonemesSentence::operator=(const JoinedPhonemesSentence& aOther)
{
    mValue_ = aOther.mValue_;
    return (*this);
}

QString JoinedPhonemesSentence::value() const
{
    return mValue_;
}

int JoinedPhonemesSentence::size() const
{
    return mValue_.size();
}

JoinedPhonemesSentence JoinedPhonemesSentence::deleteLeftSide(int aLength)
{
    return JoinedPhonemesSentence(mValue_.right(mValue_.size() - aLength));
}


