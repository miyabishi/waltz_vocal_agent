#include "wavfilepath.h"

using namespace waltz::agent::DictionaryComponent;

WavFilePath::WavFilePath(QString aValue)
    :mValue_(aValue)
{

}

WavFilePath::WavFilePath(const WavFilePath& aOther)
    :mValue_(aOther.mValue_)
{
}

WavFilePath& WavFilePath::operator=(const WavFilePath& aOther)
{
    mValue_ = aOther.mValue_;
    return (* this);
}

QString WavFilePath::value() const
{
    return mValue_;
}
