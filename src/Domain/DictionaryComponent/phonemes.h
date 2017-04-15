#ifndef PHONEMES_H
#define PHONEMES_H

#include <QString>

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class Phonemes
            {
            public:
                explicit Phonemes(const QString& aValue);
                Phonemes(const Phonemes& aOther);
                Phonemes& operator=(const Phonemes& aOther);
                bool operator==(const Phonemes& aOther);

            public:
                QString value() const;
                int length() const;

            private:
                QString mValue_;
            };
        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // PHONEMES_H
