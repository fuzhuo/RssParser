#include "RssParser.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout<<"Usage: rssParser ./samples/feed.xml"<<endl;
        return -1;
    }
    const char *rssFile = argv[1];
    RssParser *rssParser = new RssParser;
    rssParser->initWithFeedFile(rssFile);
    rssParser->dump();
    delete rssParser;
    return 0;
}

