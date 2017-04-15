#ifndef WAVFILEPATH_H
#define WAVFILEPATH_H

#include <memory>
#include <QString>

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {

            class WavFilePath
            {
            public:
                explicit WavFilePath(QString aValue);
                WavFilePath(const WavFilePath& aOther);
                WavFilePath& operator=(const WavFilePath& aOther);

                QString value() const;
            private:
                QString mValue_;
            };

        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // WAVFILEPATH_H
