#ifndef VOICEDICTIONARYPARSER_H
#define VOICEDICTIONARYPARSER_H

#include <QDomElement>
#include "src/Domain/DictionaryComponent/voicedictionary.h"
#include "src/Domain/DictionaryComponent/syllables.h"
#include "src/Domain/DictionaryComponent/syllable.h"
#include "src/Domain/DictionaryComponent/fragments.h"
#include "src/Domain/DictionaryComponent/fragment.h"
#include "src/Domain/DictionaryComponent/fixedrange.h"

namespace waltz
{
    namespace agent
    {
        namespace ConfigurationParser
        {
            class VoiceDictionaryParser
            {
            public:
                static waltz::agent::DictionaryComponent::VoiceDictionary parse(const QString& aFileName);

            private:
                static waltz::agent::DictionaryComponent::Syllables parseSyllables(const QDomElement& aSyllablesElement);
                static waltz::agent::DictionaryComponent::Syllable parseSyllable(const QDomElement& aSyllableElement);
                static waltz::agent::DictionaryComponent::Fragments parseFragments(const QDomElement& aFragmentsElement,
                                                                                   const QString& aVoiceDictionaryDirPath);
                static waltz::agent::DictionaryComponent::Fragment parseFragment(const QDomElement& aFragmentElement,
                                                                                 const QString& aVoiceDictionaryDirPath);
                static waltz::agent::DictionaryComponent::FixedRange parseFixedRange(const QDomElement& aFixedRangeElement);
                static QString getTextFromNode(const QDomNode& aNode);

            private:
                VoiceDictionaryParser();
            };
        } // namespace ConfigurationParser
    } // namespace agent
} // namespace waltz

#endif // VOICEDICTIONARYPARSER_H
