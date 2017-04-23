#ifndef VOICELIBRARYNAME_H
#define VOICELIBRARYNAME_H

#include <QString>

namespace waltz
{
    namespace agent
    {
        namespace VocalInformationComponent
        {

            class VoiceLibraryName
            {
            public:
                explicit VoiceLibraryName(const QString& aValue);
                VoiceLibraryName(const VoiceLibraryName& aOther);
                VoiceLibraryName& operator=(const VoiceLibraryName& aOther);

            public:
                QString value() const;

            private:
                QString mValue_;
            };

        } // namespace VocalInformationComponent
    } // namespace agent
} // namespace waltz

#endif // VOICELIBRARYNAME_H
