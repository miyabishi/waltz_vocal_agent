#include "voicelibraryname.h"

using namespace waltz::agent::VocalInformationComponent;

VoiceLibraryName::VoiceLibraryName(const QString& aValue)
    : mValue_(aValue)
{
}

VoiceLibraryName::VoiceLibraryName(const VoiceLibraryName &aOther)
    :mValue_(aOther.mValue_)
{
}

VoiceLibraryName& VoiceLibraryName::operator=(const VoiceLibraryName &aOther)
{
    mValue_= aOther.mValue_;
    return (*this);
}
