#include "dictionaryfilepath.h"

using namespace waltz::agent::VocalInformationComponent;

DictionaryFilePath::DictionaryFilePath(const QString& aValue)
    :mValue_(aValue)
{
}

DictionaryFilePath::DictionaryFilePath(const DictionaryFilePath &aOtehr)
    :mValue_(aOtehr.mValue_)
{
}

DictionaryFilePath& DictionaryFilePath::operator=(const DictionaryFilePath &aOtehr)
{
    mValue_ = aOtehr.mValue_;
    return (*this);
}

QString DictionaryFilePath::value() const
{
    return mValue_;
}
