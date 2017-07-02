#include <QFile>
#include <QFileInfo>
#include <QDomDocument>
#include <QDir>
#include <QtDebug>

#include "vocalinformationparser.h"
#include "src/Domain/VocalInformationComponent/characterdescription.h"
#include "src/Domain/VocalInformationComponent/characterimagefilepath.h"
#include "src/Domain/VocalInformationComponent/dictionaryfilepath.h"
#include "src/Domain/VocalInformationComponent/voicelibraryname.h"

using namespace waltz::agent::ConfigurationParser;
using namespace waltz::agent::VocalInformationComponent;

namespace
{
    const QString TAG_VOCAL_INFORMATION  = "VocalInformation";
    const QString TAG_VOICE_LIBRARY_NAME = "LibraryName";
    const QString TAG_DESCRIPTION        = "Description";
    const QString TAG_IMAGE_FILE         = "ImageFile";
    const QString TAG_DICTIONARY_FILE    = "DictionaryFile";
}

VocalInformation VocalInformationParser::parse(const QString &aFileName)
{
    QFile vocalInformationFile(aFileName);
    QFileInfo vocalInformationFileInfo(vocalInformationFile);
    QDomDocument doc;
    QString errorStr;
    int errorLine;
    int errorColumn;

    if (! vocalInformationFile.open(QIODevice::ReadOnly))
    {
        qWarning() << "can't open file." << aFileName
                   << vocalInformationFile.errorString();
        return VocalInformation();
    }

    QString voiceInformationDirPath = vocalInformationFileInfo.absoluteDir().absolutePath();

    if (! doc.setContent(&vocalInformationFile,
                         true,
                         &errorStr,
                         &errorLine,
                         &errorColumn))
    {

        qWarning() << "error"
                   << errorStr
                   << "Line"<< errorLine
                   << "column" << errorColumn;
        return VocalInformation();
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != TAG_VOCAL_INFORMATION)
    {
        qWarning() << "The dictionary is wrong format.";
        return VocalInformation();
    }

    if (root.toElement().attribute("version") != "0.1")
    {
        qWarning() << "The vocal information file is not supported version.";
        return VocalInformation();
    }

    QDomNode node = root.firstChild();
    QString imageFilePath = "";
    QString dictionaryFilePath = "";
    QString description = "";
    QString voiceLibraryName = "";

    while (!node.isNull())
    {
        if (node.toElement().tagName() == TAG_IMAGE_FILE)
        {
            imageFilePath = joinPath(voiceInformationDirPath, getTextFromNode(node));
        }
        else if (node.toElement().tagName() == TAG_DICTIONARY_FILE)
        {
            dictionaryFilePath = joinPath(voiceInformationDirPath, getTextFromNode(node));
        }
        else if (node.toElement().tagName() == TAG_DESCRIPTION)
        {
            description = getTextFromNode(node);
        }
        else if (node.toElement().tagName() == TAG_VOICE_LIBRARY_NAME)
        {
            voiceLibraryName = getTextFromNode(node);
        }

        node = node.nextSibling();
    }
    return VocalInformation(VoiceLibraryName(voiceLibraryName),
                            DictionaryFilePath(dictionaryFilePath),
                            CharacterImageFilePath(imageFilePath),
                            CharacterDescription(description));
}

VocalInformationParser::VocalInformationParser()
{

}

