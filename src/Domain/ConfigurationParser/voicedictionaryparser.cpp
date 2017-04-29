#include <QtDebug>
#include <QtXml>
#include <QFile>
#include <QFileInfo>
#include <qdom.h>
#include <QDomElement>
#include <QDomNode>
#include "voicedictionaryparser.h"
#include "src/Domain/DictionaryComponent/comment.h"
#include "src/Domain/DictionaryComponent/wavfilepath.h"

using namespace waltz::agent::ConfigurationParser;
using namespace waltz::agent::DictionaryComponent;

namespace
{
    const QString ATTRIBUTE_ALIAS    = "alias";
    const QString ATTRIBUTE_PHONEMES = "phonemes";

    const QString TAG_PHONEMES         = "Phonemes";
    const QString TAG_START_TIME       = "StartTime";
    const QString TAG_LENGTH           = "Length";
    const QString TAG_FILENAME         = "FileName";
    const QString TAG_COMMENT          = "Comment";
    const QString TAG_FIXED_RANGE      = "FixedRange";
    const QString TAG_VOICE_DICTIONARY = "VoiceDictionary";
    const QString TAG_STLLABLE         = "Syllable";
    const QString TAG_STLLABLES        = "Syllables";
    const QString TAG_FRAGMENT         = "Fragment";
    const QString TAG_FRAGMENTS        = "Fragments";

}

VoiceDictionary VoiceDictionaryParser::parse(const QString& aFileName)
{
    QFile dictionaryFile(aFileName);
    QFileInfo dictionaryFileInfo(dictionaryFile);
    QDomDocument doc;
    QString errorStr;
    int errorLine;
    int errorColumn;

    if (! dictionaryFile.open(QIODevice::ReadOnly))
    {
        qWarning() << "can't open file." << aFileName
                   << dictionaryFile.errorString();
        return VoiceDictionary();
    }
    QString voiceDictionaryDirPath = dictionaryFileInfo.absoluteDir().absolutePath();

    if (! doc.setContent(&dictionaryFile,
                         true,
                         &errorStr,
                         &errorLine,
                         &errorColumn))
    {

        qWarning() << "error"
                   << errorStr
                   << "Line"<< errorLine
                   << "column" << errorColumn;
        return VoiceDictionary();
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != TAG_VOICE_DICTIONARY)
    {
        qWarning() << "The dictionary is wrong format.";
        return VoiceDictionary();
    }
    if (root.toElement().attribute("version") != "0.1")
    {
        qWarning() << "The dictionary is not supported version.";
        return VoiceDictionary();
    }

    QDomNode node = root.firstChild();
    Syllables syllables;
    Fragments fragments;
    while (!node.isNull())
    {
        if (node.toElement().tagName() == TAG_STLLABLES)
        {
            syllables = parseSyllables(node.toElement());
        }
        else if (node.toElement().tagName() == TAG_FRAGMENTS)
        {
            fragments = parseFragments(node.toElement(),
                                       voiceDictionaryDirPath);
        }
        node = node.nextSibling();
    }
    return VoiceDictionary(syllables, fragments);
}

Fragments VoiceDictionaryParser::parseFragments(const QDomElement &aFragmentsElement,
                                                const QString& aVoiceDictionaryDirPath)
{
    QDomNode node = aFragmentsElement.firstChild();
    Fragments fragments;

    while(! node.isNull())
    {
        if (node.toElement().tagName() == TAG_FRAGMENT)
        {
            fragments.append(parseFragment(node.toElement(), aVoiceDictionaryDirPath));
        }
        node = node.nextSibling();
    }
    return fragments;
}

Fragment VoiceDictionaryParser::parseFragment(const QDomElement& aFragmentElement,
                                              const QString& aVoiceDictionaryDirPath)
{
    Phonemes   phonemes(aFragmentElement.attribute(ATTRIBUTE_PHONEMES));
    QString    fileName;
    double     startTime = 0;
    double     length = 0;
    FixedRange fixedRange;
    QString    comment = "";

    QDomNode node = aFragmentElement.firstChild();

    while(! node.isNull())
    {
        if (node.toElement().tagName() == TAG_FILENAME)
        {
            fileName = getTextFromNode(node);
        }
        else if (node.toElement().tagName() == TAG_START_TIME)
        {
            startTime = getTextFromNode(node).toDouble();
        }
        else if (node.toElement().tagName() == TAG_LENGTH)
        {
            length = getTextFromNode(node).toDouble();
        }
        else if (node.toElement().tagName() == TAG_FIXED_RANGE)
        {
            fixedRange = parseFixedRange(node.toElement());
        }
        else if (node.toElement().tagName() == TAG_COMMENT)
        {
            comment = getTextFromNode(node);
        }

        node = node.nextSibling();
    }
    return Fragment(phonemes,
                    WavFilePath(joinPath(aVoiceDictionaryDirPath, fileName)),
                    MilliSeconds(startTime),
                    MilliSeconds(length),
                    fixedRange,
                    Comment(comment));
}

FixedRange VoiceDictionaryParser::parseFixedRange(const QDomElement &aFixedRangeElement)
{
    QDomNode node = aFixedRangeElement.firstChild();
    double length = 0;
    double overlap = 0;
    double preceding = 0;

    while(! node.isNull())
    {
        if (node.toElement().tagName() == TAG_LENGTH)
        {
            length = getTextFromNode(node).toDouble();
        }
        else if(node.toElement().tagName() == "Overlap")
        {
            overlap = getTextFromNode(node).toDouble();
        }
        else if(node.toElement().tagName() == "Preceding")
        {
            preceding = getTextFromNode(node).toDouble();
        }
        node = node.nextSibling();
    }
    return FixedRange(MilliSeconds(length),
                      MilliSeconds(overlap),
                      MilliSeconds(preceding));
}

Syllables VoiceDictionaryParser::parseSyllables(const QDomElement& aSyllablesElement)
{
    QDomNode node = aSyllablesElement.firstChild();
    Syllables syllables;

    while(! node.isNull())
    {
        if (node.toElement().tagName() == "Syllable")
        {
            syllables.append(parseSyllable(node.toElement()));
        }
        node = node.nextSibling();
    }
    return syllables;
}

Syllable VoiceDictionaryParser::parseSyllable(const QDomElement& aSyllableElement)
{
    Alias alias(aSyllableElement.attribute(ATTRIBUTE_ALIAS));
    QString phonemesString;
    QDomNode node = aSyllableElement.firstChild();

    while(!node.isNull())
    {
        if (node.toElement().tagName() == TAG_PHONEMES)
        {
            phonemesString = getTextFromNode(node);
        }

        node = node.nextSibling();
    }
    return Syllable(alias,
                    Phonemes(phonemesString));
}


VoiceDictionaryParser::VoiceDictionaryParser()
{
}
