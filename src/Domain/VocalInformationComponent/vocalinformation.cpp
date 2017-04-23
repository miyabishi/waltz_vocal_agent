#include "vocalinformation.h"


using namespace waltz::agent::VocalInformationComponent;

VocalInformation::VocalInformation()
    : mVoiceLibraryName_("")
    , mDictionaryFilePath_("")
    , mImageFilePath_("")
    , mDescription_("")
{
}

VocalInformation::VocalInformation(VoiceLibraryName aVoiceLibraryName,
                                   DictionaryFilePath aDictionaryFilePath,
                                   CharacterImageFilePath aImageFilePath,
                                   CharacterDescription aDescription)
     : mVoiceLibraryName_(aVoiceLibraryName)
     , mDictionaryFilePath_(aDictionaryFilePath)
     , mImageFilePath_(aImageFilePath)
     , mDescription_(aDescription)
{
}

VocalInformation::VocalInformation(const VocalInformation& aOther)
    : mVoiceLibraryName_(aOther.mVoiceLibraryName_)
    , mDictionaryFilePath_(aOther.mDictionaryFilePath_)
    , mImageFilePath_(aOther.mImageFilePath_)
    , mDescription_(aOther.mDescription_)
{

}

DictionaryFilePath VocalInformation::dictionaryFilePath() const
{
    return mDictionaryFilePath_;
}

CharacterDescription VocalInformation::characterDescription() const
{
    return mDescription_;
}

CharacterImageFilePath VocalInformation::characterImageFilePath() const
{
    return mImageFilePath_;
}

VocalInformation& VocalInformation::operator=(const VocalInformation& aOther)
{
    mVoiceLibraryName_ = aOther.mVoiceLibraryName_;
    mDictionaryFilePath_ = aOther.mDictionaryFilePath_;
    mImageFilePath_ = aOther.mImageFilePath_;
    mDescription_ = aOther.mDescription_;

    return (*this);
}
