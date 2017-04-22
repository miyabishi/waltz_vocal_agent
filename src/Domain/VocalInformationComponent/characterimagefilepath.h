#ifndef CHARACTORIMAGEFILEPATH_H
#define CHARACTORIMAGEFILEPATH_H

#include <QString>

namespace waltz
{
    namespace agent
    {
        namespace VocalInformationComponent
        {
            class CharacterImageFilePath
            {
            public:
                explicit CharacterImageFilePath(const QString& aValue);
                CharacterImageFilePath(const CharacterImageFilePath& aOther);
                CharacterImageFilePath& operator=(const CharacterImageFilePath& aOther);

            public:
                QString value() const;

            private:
                QString mValue_;
            };

        } // namespace VocalInformationComponent
    } // namespace agent
} // namespace waltz

#endif // CHARACTORIMAGEFILEPATH_H
