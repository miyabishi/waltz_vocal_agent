#include "waltzvocalagent.h"
#include "Domain/ConfigurationParser/voicedictionaryparser.h"
#include "Domain/DictionaryComponent/voicedictionary.h"
#include <QDebug>

using namespace waltz::agent;
using namespace waltz::agent::ConfigurationParser;
using namespace waltz::agent::DictionaryComponent;

WaltzVocalAgent::WaltzVocalAgent()
{
}

void WaltzVocalAgent::loadDictionary(const QString& aFileName)
{
    mVoiceDictionary_ = std::shared_ptr<VoiceDictionary>(
                new VoiceDictionary(VoiceDictionaryParser::parse(aFileName)));
}

FragmentList WaltzVocalAgent::phraseToFragmentList(const IPhrase* aPhrase)
{
    if (aPhrase == 0)
    {
        Q_ASSERT("Phrase pointer is null.");
        return FragmentList();
    }
    return mVoiceDictionary_->phraseToFragmentList(aPhrase);
}

QString WaltzVocalAgent::phraseToPhonemesSentence(const IPhrase* aPhrase) const
{
    return mVoiceDictionary_->phraseToJoinedPhonemesSentence(aPhrase).value();
}

