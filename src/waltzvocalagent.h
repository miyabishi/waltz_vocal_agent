#ifndef WALTZVOCALAGENT_H
#define WALTZVOCALAGENT_H

#include <memory>
#include <string>
#include "waltzvocalagent_global.h"
#include "iphrase.h"
#include "fragmentlist.h"

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class VoiceDictionary;
        }
        namespace VocalInformationComponent {
            class VocalInformation;
        }

        class WALTZVOCALAGENTSHARED_EXPORT WaltzVocalAgent
        {
        public:
            WaltzVocalAgent();
            void loadVocal(const std::string& aFileName);
            FragmentList phraseToFragmentList(const IPhrase* aPhrase);
            std::string phraseToPhonemesSentence(const IPhrase* aPhrase) const;

            std::string characterDescription() const;
            std::string characterImageFilePath() const;
            std::string libraryName() const;
            std::vector<std::string> correspondenceAliasVector() const;
            bool        isLibraryLoaded() const;

        private:
            std::shared_ptr<DictionaryComponent::VoiceDictionary>        mVoiceDictionary_;
            std::shared_ptr<VocalInformationComponent::VocalInformation> mVocalInformation_;
            bool                                                         mIsLibraryLoaded_;

        private:
            WaltzVocalAgent(const WaltzVocalAgent& aOther);
            WaltzVocalAgent& operator=(const WaltzVocalAgent& aOther);
        };
    }
}

#endif // WALTZVOCALAGENT_H
