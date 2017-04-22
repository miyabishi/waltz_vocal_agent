#ifndef VOCALINFORMATION_H
#define VOCALINFORMATION_H

#include "characterdescription.h"
#include "characterimagefilepath.h"
#include "dictionaryfilepath.h"

namespace waltz
{
    namespace agent
    {
        namespace VocalInformationComponent
        {
            class VocalInformation
            {
            public:
                VocalInformation();
                VocalInformation(DictionaryFilePath aDictionaryFilePath,
                                 CharacterImageFilePath aImageFilePath,
                                 CharacterDescription aDescription);
                VocalInformation(const VocalInformation& aOther);
                VocalInformation& operator=(const VocalInformation& aOther);

            public:
                DictionaryFilePath dictionaryFilePath() const;
                CharacterDescription characterDescription() const;
                CharacterImageFilePath characterImageFilePath() const;

            private:
                DictionaryFilePath     mDictionaryFilePath_;
                CharacterImageFilePath mImageFilePath_;
                CharacterDescription   mDescription_;

            };
        }
    } // namespace agent
} // namespace waltz

#endif // VOCALINFORMATION_H
