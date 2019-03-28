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

    std::string match;
    app.add_option("match", match, "Filename match");

    size_t before = 0, after = 0;
    app.add_option("-B,--before-context", before, "Print NUM lines of leading context before matching lines");
    app.add_option("-A,--after-context", after, "Print NUM lines of trailing context after matching lines");

    bool noCaseSensitive = false;
    app.add_flag("-i,--ignore-case", noCaseSensitive, "Ignore case distinctions in PATTERN");

    bool regexSearchEngine = false;
    app.add_flag("-e,--regexp", regexSearchEngine, "Interpret PATTERNS as extended regular expressions");

    std::vector<std::string> types;
    app.add_option("-t,--type", types, "File types to search");

    bool recursive = false;
    app.add_flag("-r,--recursive", recursive, "Read all files under each directory, recursively");

    CLI11_PARSE(app, argc, argv);

    XSearch xsearch;

    xsearch.setStyle("ack");
    xsearch.setSearchEngine(regexSearchEngine ? "regex" : "regular");
    xsearch.setFileSystem("local");

    xsearch.setExtensionMatch(types);
    xsearch.setFilenameMatch(match);
    xsearch.setCaseSensitive(!noCaseSensitive);
    xsearch.setContextLine(before, after);
    xsearch.setRecursive(recursive);
    
    xsearch.start(term, dir);

    return 0;
}