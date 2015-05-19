#ifndef _RSS_PARSER_H_
#define _RSS_PARSER_H_

#include "tinyxml2/tinyxml2.h"
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>

using namespace tinyxml2;

class RssItem {
    public:
        std::string title;
        std::string link;
        std::string pubDate;
        //std::vector<std::string> category;
        std::string description;
        std::string content;
};

class RssData {
    public:
        std::string version;
        std::string title;
        std::string link;
        std::string lastBuildDate;
        std::string description;
        std::string language;
        std::vector<RssItem> items;
};

class RssParser
{
    public:
        RssParser();
        ~RssParser();
        void initWithFeedFile(const char *feedFileName);
        void initWithString(std::string xmlContent);
        void dump();
        bool parseOK;
        RssData rssData;
    private:
        XMLDocument *doc;
        void parse();
};

#endif /*_RSS_PARSER_H_*/

