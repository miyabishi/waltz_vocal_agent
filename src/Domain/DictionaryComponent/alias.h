#ifndef ALIAS_H
#define ALIAS_H

#include <QString>

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class Alias
            {
            public:
                explicit Alias(const QString& aValue);
                Alias(const Alias& aOther);
                Alias& operator=(const Alias& aOther);
                bool operator==(const Alias& aOther) const;
                bool operator!=(const Alias& aOther) const;

            private:
                QString mValue_;
            };
        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // ALIAS_H
