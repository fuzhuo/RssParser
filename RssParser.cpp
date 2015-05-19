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

void RssParser::dump()
{
    std::cout<<"Title: "<<rssData.title<<std::endl;
    std::cout<<"Version: "<<rssData.version<<std::endl;
    std::cout<<"lastBuildDate: "<<rssData.lastBuildDate<<std::endl;
    for (int i=0; i<rssData.items.size(); i++) {
        std::cout<<"-----------------item["<<i<<"]------------------------------------"<<std::endl;
        std::cout<<"items["<<i<<"].title="<<rssData.items[i].title<<std::endl;
        std::cout<<"items["<<i<<"].pubDate="<<rssData.items[i].pubDate<<std::endl;
        std::cout<<"items["<<i<<"].description="<<rssData.items[i].description<<std::endl;
    }
}

void RssParser::parse()
{
    XMLElement *root = doc->FirstChildElement();

    //version
    const char *version = root->Attribute("version");
    rssData.version = (version)?version:"";

    XMLElement *channel = root->FirstChildElement();
    //title
    const char *title = channel->FirstChildElement("title")->GetText();
    rssData.title = (title)?title:"";

    //lastBuildDate or pubDate
    XMLElement *lastBuildDataEle = channel->FirstChildElement("lastBuildDate");
    if (!lastBuildDataEle) {
        lastBuildDataEle = channel->FirstChildElement("pubDate");
    }
    const char *lastBuildData = NULL;
    if (lastBuildDataEle) {
        lastBuildData = lastBuildDataEle->GetText();
    }
    rssData.lastBuildDate = (lastBuildData)?lastBuildData:"";

    //items
    XMLElement *item0 = channel->FirstChildElement("item");
    for( ; item0; item0=item0->NextSiblingElement())
    {
        RssItem item;
        const char *item_title=item0->FirstChildElement("title")->GetText();
        const char *item_description=item0->FirstChildElement("description")->GetText();
        const char *pubDate = item0->FirstChildElement("pubDate")->GetText();
        item.title = item_title;
        item.description = item_description;
        XMLElement *contentEle = item0->FirstChildElement("content:encoded");
        if (contentEle) {
            const char *item_content = contentEle->GetText();
            if (item_content) item.description+=item_content;
        }
        item.pubDate = pubDate;
        rssData.items.push_back(item);
    }
    dump();
}

