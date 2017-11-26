#include "waltzvocalagent.h"
#include "Domain/ConfigurationParser/voicedictionaryparser.h"
#include "Domain/DictionaryComponent/voicedictionary.h"
#include "Domain/VocalInformationComponent/vocalinformation.h"
#include "Domain/ConfigurationParser/vocalinformationparser.h"

using namespace waltz::agent;
using namespace waltz::agent::ConfigurationParser;
using namespace waltz::agent::DictionaryComponent;
using namespace waltz::agent::VocalInformationComponent;

WaltzVocalAgent::WaltzVocalAgent()
    : mIsLibraryLoaded_(false)
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
    mIsLibraryLoaded_ = true;
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

std::string WaltzVocalAgent::characterDescription() const
{
    return mVocalInformation_->characterDescription().value().toStdString();
}

std::string WaltzVocalAgent::characterImageFilePath() const
{
    return mVocalInformation_->characterImageFilePath().value().toStdString();
}

std::string WaltzVocalAgent::libraryName() const
{
    return mVocalInformation_->voiceLibraryName().value().toStdString();
}

bool WaltzVocalAgent::isLibraryLoaded() const
{
    return mIsLibraryLoaded_;
}
