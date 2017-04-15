#include "phrase.h"
#include "alias.h"

using namespace waltz::example;
using namespace waltz::agent;

Phrase::Phrase()
    :mAliases_()
{
}

Phrase::~Phrase()
{
    for(waltz::agent::IAlias* alias: mAliases_)
    {
        delete alias;
    }
    mAliases_.clear();
}

Phrase::Phrase(const Phrase &aOther)
    :mAliases_(aOther.mAliases_)
{
}

Phrase& Phrase::operator=(const Phrase& aOther)
{
    mAliases_ = aOther.mAliases_;
    return (*this);
}

void Phrase::append(const std::string& aAlias)
{
    mAliases_.push_back((waltz::agent::IAlias*)(new Alias(aAlias)));
}

std::vector<IAlias*> Phrase::aliases() const
{
    return mAliases_;
}
