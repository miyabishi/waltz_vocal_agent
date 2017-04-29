#include "comment.h"

using namespace waltz::agent::DictionaryComponent;

Comment::Comment(const QString& aValue)
    : mValue_(aValue)
{
}

Comment::Comment(const Comment &aOther)
    : mValue_(aOther.mValue_)
{
}

Comment& Comment::operator=(const Comment &aOther)
{
    mValue_ = aOther.mValue_;
    return (*this);
}

QString Comment::value() const
{
    return mValue_;
}
