#include "alias.h"
using namespace waltz::agent::DictionaryComponent;


Alias::Alias(const QString& aValue)
    :mValue_(aValue)
{
}

Alias::Alias(const Alias &aOther)
    :mValue_(aOther.mValue_)
{

}

Alias& Alias::operator=(const Alias& aOther)
{
    mValue_ = aOther.mValue_;
    return (*this);
}

bool Alias::operator==(const Alias& aOther) const
{
    return mValue_ == aOther.mValue_;
}

bool Alias::operator!=(const Alias& aOther) const
{
    return mValue_ != aOther.mValue_;
}
