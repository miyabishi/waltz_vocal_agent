#ifndef ALIAS_H
#define ALIAS_H

#include <string>
#include <ialias.h>

namespace waltz
{
    namespace example
    {
        class Alias : public waltz::agent::IAlias
        {
        public:
            explicit Alias(std::string aValue);
            Alias(const Alias& aOther);
            Alias& operator=(const Alias& aOther);

        public:
            std::string value() const;

        private:
            std::string mValue_;
        };
    } // namespace engine
} // namespace waltz

#endif // ALIAS_H
