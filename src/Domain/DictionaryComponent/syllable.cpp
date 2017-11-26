#include "syllable.h"

using namespace waltz::agent::DictionaryComponent;

Syllable::Syllable()
    : mAlias_(QString())
    , mPhonemes_(QString())
{
}

Syllable::Syllable(const Alias& aAlias,
                   const Phonemes& aPhonemes)
    : mAlias_(aAlias)
    , mPhonemes_(aPhonemes)
{
}

Syllable::Syllable(const Syllable& aOther)
    : mAlias_(aOther.mAlias_)
    , mPhonemes_(aOther.mPhonemes_)
{
}

Syllable& Syllable::operator=(const Syllable& aOther)
{
    mAlias_ = aOther.mAlias_;
    mPhonemes_ = aOther.mPhonemes_;
    return (* this);
}

bool Syllable::aliasEquals(const Alias& aAlias) const
{
    return mAlias_ == aAlias;
}

Phonemes Syllable::phonemes() const
{
    return mPhonemes_;
}
