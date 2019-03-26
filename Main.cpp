#include <string>

#include "XSearch.h"
#include "CLI11.hpp"

int main(int argc, char** argv)
{
    CLI::App app("X-Search");

    std::string term;
    app.add_option("term", term, "Term to search")->required();

    std::string dir = ".";
    app.add_option("dir", dir, "Search in directroy");

    size_t before = 0, after = 0, context = 0;
    app.add_option("-B,--before-context", before);
    app.add_option("-A,--after-context", after);
    app.add_option("-C,--context", context);

    if (context)
    {
        before = context;
        after  = context;
    }

    bool noCaseSensitive = false;
    app.add_flag("-i,--ignore-case", noCaseSensitive);

    CLI11_PARSE(app, argc, argv);

    XSearch xsearch;

    xsearch.setStyle("ack");
    xsearch.setSearchEngine("regular");
    xsearch.setFileSystem("local");

    xsearch.setCaseSensitive(!noCaseSensitive);
    xsearch.setContextLine(before, after);
    
    xsearch.start(term, dir);

    return 0;
}