#include "phonemes.h"

using namespace waltz::agent::DictionaryComponent;

Phonemes::Phonemes(const QString& aValue)
    :mValue_(aValue)
{
}

Phonemes::Phonemes(const Phonemes &aOther)
    :mValue_(aOther.mValue_)
{
}

Phonemes& Phonemes::operator=(const Phonemes& aOther)
{
    mValue_ = aOther.mValue_;
    return (*this);
}

bool Phonemes::operator==(const Phonemes& aOther)
{
    return mValue_ == aOther.mValue_;
}

QString Phonemes::value() const
{
    return mValue_;
}

int Phonemes::length() const
{
    return mValue_.length();
}
