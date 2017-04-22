#ifndef CHARACTERDESCRIPTION_H
#define CHARACTERDESCRIPTION_H

#include <QString>

namespace waltz
{
    namespace agent
    {
        namespace VocalInformationComponent
        {
            class CharacterDescription
            {
            public:
                explicit CharacterDescription(const QString& aValue);
                CharacterDescription(const CharacterDescription& aOther);
                CharacterDescription& operator=(const CharacterDescription& aOther);

            public:
                QString value() const;

            private:
                QString mValue_;
            };

        } // namespace VocalInformationComponent
    } // namespace agent
} // namespace waltz

#endif // CHARACTERDESCRIPTION_H
