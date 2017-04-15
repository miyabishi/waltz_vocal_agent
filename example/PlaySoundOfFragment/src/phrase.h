#ifndef PHRASE_H
#define PHRASE_H

#include <string>
#include <QList>
#include <iphrase.h>
#include <ialias.h>

namespace waltz
{
    namespace example
    {
        class Phrase : public waltz::agent::IPhrase
        {
        public:
            Phrase();
            ~Phrase();

            Phrase(const Phrase& aOther);
            Phrase& operator=(const Phrase& aOther);

        public:
            std::vector<waltz::agent::IAlias*>aliases() const;
            void append(const std::string& alias);

        private:
            std::vector<waltz::agent::IAlias*> mAliases_;
        };
    } // namespace engine
} // namespace waltz

#endif // PHRASE_H
