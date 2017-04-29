#include <QDebug>
#include <QDir>
#include "src/Domain/Wave/wavfile.h"
#include "fragment.h"

using namespace waltz::agent::DictionaryComponent;

Fragment::Fragment()
    : mPhonemes_(Phonemes(""))
    , mWavFilePath_(WavFilePath(""))
    , mStartTime_(0)
    , mLength_(0.0)
    , mFixedRange_(FixedRange())
    , mComment_("")
{

}

Fragment::Fragment(const Phonemes& aPhonemes,
                   const WavFilePath& aWavFilePath,
                   MilliSeconds aStartTime,
                   MilliSeconds aLength,
                   const FixedRange& aFixedRange,
                   const Comment& aComment)
    : mPhonemes_(aPhonemes)
    , mWavFilePath_(aWavFilePath)
    , mStartTime_(aStartTime)
    , mLength_(aLength)
    , mFixedRange_(aFixedRange)
    , mComment_(aComment)
{
}

Fragment::Fragment(const Fragment& aOther)
    : mPhonemes_(aOther.mPhonemes_)
    , mWavFilePath_(aOther.mWavFilePath_)
    , mStartTime_(aOther.mStartTime_)
    , mLength_(aOther.mLength_)
    , mFixedRange_(aOther.mFixedRange_)
    , mComment_(aOther.mComment_)
{
}

Fragment& Fragment::operator=(const Fragment& aOther)
{
    mPhonemes_    = aOther.mPhonemes_;
    mWavFilePath_ = aOther.mWavFilePath_;
    mStartTime_   = aOther.mStartTime_;
    mLength_      = aOther.mLength_;
    mFixedRange_  = aOther.mFixedRange_;
    mComment_     = aOther.mComment_;

    return (*this);
}

Phonemes Fragment::phonemes() const
{
    return mPhonemes_;
}

bool Fragment::matchPhonemsAtHead(const JoinedPhonemesSentence& aJoinedPhonemesSentence) const
{
    return aJoinedPhonemesSentence.value().indexOf(mPhonemes_.value()) == 0;
}

waltz::agent::Wave::WaveformPointer Fragment::waveform() const
{
    waltz::agent::Wave::WavFile wavFile;
    wavFile.open(mWavFilePath_.value());
    return wavFile.trim(mStartTime_, mLength_);
}

FixedRange Fragment::fixedRange() const
{
    return mFixedRange_;
}

MilliSeconds Fragment::length() const
{
    return mLength_;
}

Comment Fragment::comment() const
{
    return mComment_;
}
