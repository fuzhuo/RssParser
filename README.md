# RssParser
A RssParser based on tinyXML2 implemented by C++

##Usage:

git clone https://github.com/fuzhuo/RssParser.git

+ run `make fetch3rd` to clone tinyxml2
+ run `make` to compile

+ `make run` to run the test

```
    #include "RssParser.h"
    RssParser *rssparser = new RssParser();
    rssparser->initWithFeedFile("./test.xml");
    rssparser->dump();
    delete rssparser;
```

##Data structs
```
    rssparser->rssData;
    
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
```
done.
