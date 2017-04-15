#ifndef WALTZVOCALAGENT_H
#define WALTZVOCALAGENT_H

#include <memory>
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

        class WALTZVOCALAGENTSHARED_EXPORT WaltzVocalAgent
        {
        public:
            WaltzVocalAgent();
            void loadDictionary(const QString& aFileName);
            FragmentList phraseToFragmentList(const IPhrase* aPhrase);
            QString phraseToPhonemesSentence(const IPhrase* aPhrase) const;

        private:
            std::shared_ptr<DictionaryComponent::VoiceDictionary> mVoiceDictionary_;

        private:
            WaltzVocalAgent(const WaltzVocalAgent& aOther);
            WaltzVocalAgent& operator=(const WaltzVocalAgent& aOther);
        };
    }
}

#endif // WALTZVOCALAGENT_H
