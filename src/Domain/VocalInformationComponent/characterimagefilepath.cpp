#include "characterimagefilepath.h"

using namespace waltz::agent::VocalInformationComponent;

CharacterImageFilePath::CharacterImageFilePath(const QString& aValue)
    : mValue_(aValue)
{
}

CharacterImageFilePath::CharacterImageFilePath(const CharacterImageFilePath& aOther)
    : mValue_(aOther.mValue_)
{
}

CharacterImageFilePath& CharacterImageFilePath::operator=(const CharacterImageFilePath& aOther)
{
    mValue_ = aOther.mValue_;
    return (*this);
}

QString CharacterImageFilePath::value() const
{
    return mValue_;
}
