#ifndef PHONEMESSENTENCE_H
#define PHONEMESSENTENCE_H

#include <QList>
#include <QString>
#include "phonemes.h"
#include "joinedphonemessentence.h"

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class PhonemesSentence
            {
            public:
                PhonemesSentence();
                PhonemesSentence(const PhonemesSentence& aOther);
                PhonemesSentence& operator=(const PhonemesSentence& aOther);

            public:
                void append(Phonemes aPhonemes);
                JoinedPhonemesSentence join() const;

            private:
                QList<Phonemes> mPhonemesSentence_;
            };
        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // PHONEMESSENTENCE_H
