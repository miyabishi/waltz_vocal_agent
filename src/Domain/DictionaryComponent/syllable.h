#ifndef SYLABLE_H
#define SYLABLE_H

#include <QString>
#include "phonemes.h"
#include "alias.h"

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class Syllable
            {
            public:
                Syllable();
                Syllable(const Alias& aAlias_,
                         const Phonemes& aPhonemes);
                Syllable(const Syllable& aOther);
                Syllable& operator=(const Syllable& aOther);
                bool aliasEquals(const Alias& aAlias) const;
                Phonemes phonemes() const;

            private:
                Alias    mAlias_;
                Phonemes mPhonemes_;
            };
        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // SYLABLE_H
