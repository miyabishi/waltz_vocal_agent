#ifndef DICTIONARYFILEPATH_H
#define DICTIONARYFILEPATH_H

#include <QString>

namespace waltz
{
    namespace agent
    {
        namespace VocalInformationComponent
        {

            class DictionaryFilePath
            {
            public:
                explicit DictionaryFilePath(const QString& aValue);
                DictionaryFilePath(const DictionaryFilePath& aOtehr);
                DictionaryFilePath& operator=(const DictionaryFilePath& aOther);

            public:
                QString value() const;

            private:
                QString mValue_;
            };

        } // namespace VocalInformationComponent
    } // namespace agent
} // namespace waltz

#endif // DICTIONARYFILEPATH_H
