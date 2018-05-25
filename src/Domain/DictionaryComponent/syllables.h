#ifndef SYLLABLES_H
#define SYLLABLES_H

#include <QList>
#include "syllable.h"

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class Alias;
            class Syllables
            {
            public:
                Syllables();
                Syllables(const Syllables& aOther);
                Syllables& operator=(const Syllables& aOther);

            public:
                void append(const Syllable& aSyllable);
                Syllable find(const Alias& aAlias) const;
                std::vector<std::string> correspondenceAliasVector() const;

            private:
                QList<Syllable> mSylables_;
            };
        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // SYLLABLES_H
