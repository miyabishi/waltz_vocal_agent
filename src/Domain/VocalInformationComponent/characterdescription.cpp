#include "characterdescription.h"

using namespace waltz::agent::VocalInformationComponent;

CharacterDescription::CharacterDescription(const QString& aValue)
    :mValue_(aValue)
{

}

CharacterDescription::CharacterDescription(const CharacterDescription& aOther)
    :mValue_(aOther.mValue_)
{

}

CharacterDescription& CharacterDescription::operator=(const CharacterDescription& aOther)
{
    mValue_ = aOther.mValue_;
    return (*this);
}

QString CharacterDescription::value() const
{
    return mValue_;
}
