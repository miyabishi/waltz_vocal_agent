#include "syllables.h"

using namespace waltz::agent::DictionaryComponent;

Syllables::Syllables()
{

}

Syllables::Syllables(const Syllables& aOther)
    :mSylables_(aOther.mSylables_)
{
}

Syllables& Syllables::operator=(const Syllables& aOther)
{
    mSylables_ = aOther.mSylables_;
    return (* this);
}

void Syllables::append(const Syllable &aSyllable)
{
    mSylables_.append(aSyllable);
}

Syllable Syllables::find(const Alias& aAlias) const
{
    foreach (Syllable syllabe, mSylables_) {
        if (syllabe.aliasEquals(aAlias))
        {
            return syllabe;
        }
    }
    Q_ASSERT("Syllable Not Found");
    return Syllable();
}
