#include "alias.h"

using namespace waltz::example;

Alias::Alias(std::string aValue)
    :mValue_(aValue)
{
}

Alias::Alias(const Alias& aOther)
    :mValue_(aOther.mValue_)
{
}

Alias& Alias::operator=(const Alias &aOther)
{
    mValue_ = aOther.mValue_;
    return (*this);
}

std::string Alias::value() const
{
    return mValue_;
}
