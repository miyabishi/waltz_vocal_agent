#include <QString>

#ifndef VOCALINFORMATIONPARSER_H
#define VOCALINFORMATIONPARSER_H

#include "parser.h"
#include "src/Domain/VocalInformationComponent/vocalinformation.h"

namespace waltz
{
    namespace agent
    {
        namespace ConfigurationParser
        {
            class VocalInformationParser : public Parser
            {
            public:
                static waltz::agent::VocalInformationComponent::VocalInformation parse(const QString& aFileName);

            private:
                VocalInformationParser();
            };
        }
    } // namespace agent
} // namespace waltz

#endif // VOCALINFORMATIONPARSER_H
