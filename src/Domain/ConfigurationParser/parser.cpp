
#include <QDir>
#include <QDomNode>
#include <QDomText>
#include "parser.h"

using namespace waltz::agent::ConfigurationParser;

Parser::Parser()
{

}

QString Parser::getTextFromNode(const QDomNode& aNode)
{
    QDomNode node = aNode.firstChild();
    if(node.nodeType() != QDomNode::TextNode)
    {
        return QString();
    }
    return node.toText().data();
}

QString Parser::joinPath(const QString& aDirPath,
                         const QString& aFileName)
{
    return QDir::cleanPath(aDirPath
                           + QDir::separator()
                           + aFileName);
}
