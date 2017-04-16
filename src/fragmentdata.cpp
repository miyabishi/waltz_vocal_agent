#include <QDebug>
#include "fragmentdata.h"
#include "length.h"
#include "Domain/Wave/waveform.h"
#include "Domain/DictionaryComponent/fragment.h"

using namespace waltz::agent;
using namespace waltz::agent::DictionaryComponent;
using namespace waltz::agent::Wave;

FragmentData::FragmentData(const Fragment& aFragment)
    : mFragment_(new Fragment(aFragment))
    , mWaveform_(mFragment_->waveform())
{
}

FragmentData::FragmentData(const FragmentData& aOther)
    :mFragment_(aOther.mFragment_)
    , mWaveform_(aOther.mWaveform_)

{
}

FragmentData& FragmentData::operator=(const FragmentData& aOther)
{
    mFragment_ = aOther.mFragment_;
    mWaveform_ = aOther.mWaveform_;
    return (*this);
}

FragmentData::~FragmentData()
{
}

std::string FragmentData::phonemes() const
{
    return mFragment_->phonemes().value().toStdString();
}

std::vector<int> FragmentData::waveform() const
{
    if (mWaveform_ == 0)
    {
        qWarning("Waveform is null.");
        return std::vector<int>();
    }

    return mWaveform_->waveformValues().toVector().toStdVector();
}

Length FragmentData::length() const
{
    if (mWaveform_ == 0)
    {
        qWarning("Waveform is null.");
        return Length(MilliSeconds(0), 0, 0);
    }
    return Length(mFragment_->length(),
                  mWaveform_->sampleRate(),
                  mWaveform_->sampleSize());
}

Length FragmentData::lengthOfFixedRange() const
{
    if (mWaveform_ == 0)
    {
        qWarning("Waveform is null.");
        return Length(MilliSeconds(0), 0, 0);
    }
    return Length(mFragment_->fixedRange().length(),
                  mWaveform_->sampleRate(),
                  mWaveform_->sampleSize());
}

Length FragmentData::overlap() const
{
    if (mWaveform_ == 0)
    {
        qWarning("Waveform is null.");
        return Length(MilliSeconds(0), 0, 0);
    }
    return Length(mFragment_->fixedRange().overlap(),
                  mWaveform_->sampleRate(),
                  mWaveform_->sampleSize());
}

Length FragmentData::preceding() const
{
    if (mWaveform_ == 0)
    {
        qWarning("Waveform is null.");
        return Length(MilliSeconds(0), 0, 0);
    }
    return Length(mFragment_->fixedRange().preceding(),
                  mWaveform_->sampleRate(),
                  mWaveform_->sampleSize());
}

int FragmentData::sampleRate() const
{
    if (mWaveform_ == 0)
    {
        qWarning("Waveform is null.");
        return 0;
    }
    return mWaveform_->sampleRate();
}

int FragmentData::sampleSize() const
{
    if (mWaveform_ == 0)
    {
        qWarning("Waveform is null.");
        return 0;
    }
    return mWaveform_->sampleSize();
}

char* FragmentData::waveformRawData() const
{
    return mWaveform_->rawData().data();
}

int FragmentData::waveformRawDataSize() const
{
    return mWaveform_->rawData().size();
}
