#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <memory>
#include <QString>
#include <QList>
#include "fixedrange.h"
#include "phonemes.h"
#include "src/Domain/Wave/waveform.h"
#include "comment.h"
#include "joinedphonemessentence.h"
#include "wavfilepath.h"
#include "milliseconds.h"

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {
            class Fragment
            {
            public:
                Fragment();
                Fragment(const Phonemes& aPhonemes,
                         const WavFilePath& aWavFilePath,
                         MilliSeconds aStartTime,
                         MilliSeconds aLenght,
                         const FixedRange& aFixedRange,
                         const Comment& aComment);
                Fragment(const Fragment& aOther);
                Fragment& operator=(const Fragment& aOther);

            public:
                bool matchPhonemsAtHead(const JoinedPhonemesSentence& aJoinedPhonemesSentence) const;
                Phonemes phonemes() const;
                MilliSeconds length() const;
                FixedRange fixedRange() const;
                Comment comment() const;
                waltz::agent::Wave::WaveformPointer waveform() const;

            private:
                Phonemes      mPhonemes_;
                WavFilePath   mWavFilePath_;
                MilliSeconds  mStartTime_;
                MilliSeconds  mLength_;
                FixedRange    mFixedRange_;
                Comment       mComment_;
            };
            typedef std::shared_ptr<Fragment> FragmentPointer;
        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // FRAGMENT_H
