#include <vector>
#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QThread>

#include <stdio.h>
#include <iostream>
#include <fragmentlist.h>
#include <samephonemefragmentsets.h>
#include <fragmentdata.h>
#include <length.h>
#include "src/alias.h"
#include "src/phrase.h"
#include "src/soundplayer.h"
#include "waltzvocalagent.h"

using namespace waltz::example;
using namespace waltz::agent;


void displayFragmentDataSpec(const FragmentData& aFragmentData)
{
    qDebug() << "---";
    qDebug() << "Sample rate:"                     << aFragmentData.sampleRate();
    qDebug() << "Sample size:"                     << aFragmentData.sampleSize();
    qDebug() << "Phonemes:"                        << aFragmentData.phonemes().c_str();
    qDebug() << "Comment:"                         << aFragmentData.comment().c_str();
    qDebug() << "Length(msec):"                    << aFragmentData.length().asMilliSeconds();
    qDebug() << "Length(array length):"            << aFragmentData.length().asArrayLength();
    qDebug() << "FixedRange Length(msec):"         << aFragmentData.lengthOfFixedRange().asMilliSeconds();
    qDebug() << "FixedRange Length(array length):" << aFragmentData.lengthOfFixedRange().asArrayLength();
    qDebug() << "Overlap(msec):"                   << aFragmentData.overlap().asMilliSeconds();
    qDebug() << "Overlap(frames):"                 << aFragmentData.overlap().asArrayLength();
    qDebug() << "Preceding(msec):"                 << aFragmentData.preceding().asMilliSeconds();
    qDebug() << "Preceding(array length):"         << aFragmentData.preceding().asArrayLength();
    qDebug() << "waveform size:"                   << aFragmentData.waveform().size();
    qDebug() << "waveform rawdata size"            << aFragmentData.waveformRawDataSize();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    waltz::agent::WaltzVocalAgent agent;
    agent.loadVocal(".\\sample_vocal\\sample_vocal.wvocal");
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

    qDebug() << "description:" << QString::fromStdString(agent.characterDescription());
    qDebug() << "image file:" <<  QString::fromStdString(agent.characterImageFilePath());
    qDebug() << "phonemes" << QString::fromStdString(agent.phraseToPhonemesSentence(&phrase));

    SoundPlayer player(&a);
    QByteArray soundData;
    QDataStream dataStream(&soundData, QIODevice::ReadWrite);
    int sampleRate = fragmentList.at(0).at(0).sampleRate();
    int sampleSize = fragmentList.at(0).at(0).sampleSize();
    player.start(dataStream.device(), sampleRate, sampleSize);
    QThread::sleep(1);

    for(int i = 0; i < fragmentList.length(); i++)
    {
        FragmentData fragmentData = fragmentList.at(i).at(0);

        displayFragmentDataSpec(fragmentData);
        soundData += QByteArray(fragmentData.waveformRawData(),
                                fragmentData.waveformRawDataSize());
        sampleRate = fragmentData.sampleRate();
        sampleSize = fragmentData.sampleSize();
    }

    return a.exec();
}

