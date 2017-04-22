#include "waltzvocalagent.h"
#include "Domain/ConfigurationParser/voicedictionaryparser.h"
#include "Domain/DictionaryComponent/voicedictionary.h"
#include "Domain/VocalInformationComponent/vocalinformation.h"
#include "Domain/ConfigurationParser/vocalinformationparser.h"
#include <QDebug>

using namespace waltz::agent;
using namespace waltz::agent::ConfigurationParser;
using namespace waltz::agent::DictionaryComponent;
using namespace waltz::agent::VocalInformationComponent;

WaltzVocalAgent::WaltzVocalAgent()
{
}

void WaltzVocalAgent::loadVocal(const std::string& aFileName)
{

    mVocalInformation_ = std::shared_ptr<VocalInformation>(new VocalInformation(
                    VocalInformationParser::parse(
                        QString::fromStdString(aFileName))));
    DictionaryFilePath dictionaryFilePath = mVocalInformation_->dictionaryFilePath();

    mVoiceDictionary_  = std::shared_ptr<VoiceDictionary>(new VoiceDictionary(
                                   VoiceDictionaryParser::parse(dictionaryFilePath.value())));
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

std::string WaltzVocalAgent::phraseToPhonemesSentence(const IPhrase* aPhrase) const
{
    return mVoiceDictionary_->phraseToJoinedPhonemesSentence(aPhrase).value().toStdString();
}

std::string WaltzVocalAgent::getCharacterDescription() const
{
    return mVocalInformation_->characterDescription().value().toStdString();
}

std::string WaltzVocalAgent::getCharacterImageFilePath() const
{
    return mVocalInformation_->characterImageFilePath().value().toStdString();
}


