#include "RssParser.h"

RssParser::RssParser()
{
    parseOK=false;
    doc = new XMLDocument;
}

RssParser::~RssParser()
{
    delete doc;
}

void RssParser::initWithFeedFile(const char *feedFileName)
{
    doc->LoadFile(feedFileName);
    int errID = doc->ErrorID();
    if (errID) {
        std::cout<<"Error load file: "<<feedFileName<<std::endl;
        parseOK=false;
        return;
    }
    parse();
}

void RssParser::initWithString(std::string xmlContent)
{
    doc->Parse(xmlContent.c_str());
    int errID = doc->ErrorID();
    if (errID) {
        std::cout<<"Error parse xmlContent"<<std::endl;
        parseOK=false;
        return;
    }
    parse();
}

void RssParser::debug()
{
}

void RssParser::parse()
{
    XMLElement *root = doc->FirstChildElement();
    std::cout<<"FirstChild: "<<root->GetText()<<std::endl;
}

