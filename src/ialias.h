#ifndef ISYLLABLE_H
#define ISYLLABLE_H

#include <string>

namespace waltz
{
    namespace agent
    {
        class IAlias
        {
        public:
            virtual ~IAlias(){}
            virtual std::string value() const = 0;
        };
    }
}

#endif // ISYLLABLE_H
