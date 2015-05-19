target=rssparser
${target}: main.cpp RssParser.cpp tinyxml2/tinyxml2.cpp
	g++ -g main.cpp RssParser.cpp tinyxml2/tinyxml2.cpp -o ${target}
run: ${target}
	./${target} ./samples/feed.xml
clean:
	rm -rf ${target}
fetch3rd:
	git clone https://github.com/leethomason/tinyxml2.git
