#ifndef IPHRASE_H
#define IPHRASE_H

#include <vector>
#include "ialias.h"

namespace waltz
{
    namespace agent
    {
        class IPhrase
        {
        public:
            virtual ~IPhrase(){}
            virtual std::vector<IAlias*> aliases() const = 0;
        };
    }
}

#endif // IPHRASE_H
