#ifndef PARSER_H
#define PARSER_H

#include <QString>

namespace waltz
{
    namespace agent
    {
        namespace ConfigurationParser
        {

            class Parser
            {
            protected:
                static QString getTextFromNode(const QDomNode& aNode);
                static QString joinPath(const QString& aDirPath,
                                        const QString& aFileName);

                Parser();

            private:
                Parser(const Parser& aOther);
                Parser& operator=(const Parser& aOther);
            };

        } // namespace ConfigurationParser
    } // namespace agent
} // namespace waltz

#endif // PARSER_H
