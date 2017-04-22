#include "vocalinformation.h"


using namespace waltz::agent::VocalInformationComponent;

VocalInformation::VocalInformation()
    : mDictionaryFilePath_("")
    , mImageFilePath_("")
    , mDescription_("")
{
}

VocalInformation::VocalInformation(DictionaryFilePath aDictionaryFilePath,
                                    CharacterImageFilePath aImageFilePath,
                                    CharacterDescription aDescription)
     : mDictionaryFilePath_(aDictionaryFilePath)
     , mImageFilePath_(aImageFilePath)
     , mDescription_(aDescription)
{
}

VocalInformation::VocalInformation(const VocalInformation& aOther)
    : mDictionaryFilePath_(aOther.mDictionaryFilePath_)
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
    mDictionaryFilePath_ = aOther.mDictionaryFilePath_;
    mImageFilePath_ = aOther.mImageFilePath_;
    mDescription_ = aOther.mDescription_;

    return (*this);
}
