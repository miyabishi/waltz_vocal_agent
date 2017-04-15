#ifndef JOINEDPHONEMESSENTENCE_H
#define JOINEDPHONEMESSENTENCE_H

#include <QString>

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class JoinedPhonemesSentence
            {
            public:
                explicit JoinedPhonemesSentence(const QString& aValue);
                JoinedPhonemesSentence(const JoinedPhonemesSentence& aOther);
                JoinedPhonemesSentence& operator=(const JoinedPhonemesSentence& aOther);
            public:
                QString value() const;
                JoinedPhonemesSentence deleteLeftSide(int aLength);
                int size() const;

            private:
                QString mValue_;
            };
        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // JOINEDPHONEMESSENTENCE_H
