#include <vector>
#include <QCoreApplication>
#include <QDebug>

#include <stdio.h>
#include <fragmentlist.h>
#include <samephonemefragmentsets.h>
#include <fragmentdata.h>
#include <length.h>
#include "src/alias.h"
#include "src/phrase.h"
#include "src/soundplayer.h"
#include "waltzvocalagent.h"

#include <QTime>

using namespace waltz::example;
using namespace waltz::agent;

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(5);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void displayFragmentDataSpec(const FragmentData& aFragmentData)
{
    qDebug() << "---";
    qDebug() << "Sample rate:"               << aFragmentData.sampleRate();
    qDebug() << "Sample size:"               << aFragmentData.sampleSize();
    qDebug() << "Phonemes:"                  << aFragmentData.phonemes().c_str();
    qDebug() << "Length(msec):"              << aFragmentData.length().asMilliSeconds();
    qDebug() << "Length(frames):"            << aFragmentData.length().asFrames();
    qDebug() << "FixedRange Length(msec):"   << aFragmentData.lengthOfFixedRange().asMilliSeconds();
    qDebug() << "FixedRange Length(frames):" << aFragmentData.lengthOfFixedRange().asFrames();
    qDebug() << "Overlap(msec):"             << aFragmentData.overlap().asMilliSeconds();
    qDebug() << "Overlap(frames):"           << aFragmentData.overlap().asFrames();
    qDebug() << "Preceding(msec):"           << aFragmentData.preceding().asMilliSeconds();
    qDebug() << "Preceding(frames):"         << aFragmentData.preceding().asFrames();
    qDebug() << "waveform size:"             << aFragmentData.waveform().size();
    qDebug() << "waveform rawdata size"      << aFragmentData.waveformRawDataSize();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    waltz::agent::WaltzVocalAgent agent;
    agent.loadDictionary(".\\sample_vocal\\voice_dictionary.xml");
    Phrase phrase;

    std::vector<std::string> aliases = {
        "こ",
        "ね",
        "こ"
    };

    for(std::string alias : aliases)
    {
        phrase.append(alias);
    }

    FragmentList fragmentList = agent.phraseToFragmentList(&phrase);

    qDebug() << agent.phraseToPhonemesSentence(&phrase);
    SoundPlayer player(&a);
    for(int i = 0; i < fragmentList.length(); i++)
    {
        SamePhonemeFragmentSets samePhonemeFragmentSets = fragmentList.at(i);
        displayFragmentDataSpec(samePhonemeFragmentSets.at(0));
        player.play(samePhonemeFragmentSets.at(0));
        delay();
    }

    return a.exec();
}

