#ifndef COMMENT_H
#define COMMENT_H

#include <QString>

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {

            class Comment
            {
            public:
                Comment(const QString& aValue);
                Comment(const Comment& aOther);
                Comment& operator=(const Comment& aOther);
            public:
                QString value() const;

            private:
                QString mValue_;

            };

        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // COMMENT_H
