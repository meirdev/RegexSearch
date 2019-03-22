#include "CLI11.hpp"
#include "Configuration.h"
#include "Runnable/Search.h"

Configuration* g_configuration;

int main(int argc, char** argv)
{
    g_configuration = Configuration::getInstance();

    CLI::App app("Search");

    app.add_option("search", g_configuration->m_searchText, "Text to search")->required();
    app.add_option("files", g_configuration->m_files, "Search in directroy");
    app.add_option("-A,--after-context", g_configuration->m_afterContext, "Print NUM lines of trailing context after matching lines.");
    app.add_option("-B,--before-context",  g_configuration->m_beforeContext, "Print NUM lines of leading context before matching lines.");

    app.add_flag("-i,--ignore-case", g_configuration->m_ignoreCase, "Ignore case distinctions in PATTERN.");
    app.add_flag("-w,--word-regexp", g_configuration->m_wholeWords, "Force PATTERN to match only whole words.");
    app.add_flag("--onlyFilename", g_configuration->m_onlyFilename, "Show only file name without matchs");
    app.add_flag("--inlineFilename", g_configuration->m_inlineFilename, "Show file name in same line with match");
    app.add_flag("--allFiles", g_configuration->m_allFiles, "Show all files");

    bool flagNoColor = false;
    app.add_flag("--no-color", flagNoColor, "No highlight the matching text");

    app.add_flag("-e", g_configuration->m_regex, "Regex PATTERN");

    bool flagNoRecure = false;
    app.add_flag("-n,--no-recurse", flagNoRecure, "No descending into subdirectories");

    CLI11_PARSE(app, argc, argv);

    if (flagNoRecure)
    {
        g_configuration->m_recurse = false;
    }

    if (g_configuration->m_regex)
    {
        g_configuration->m_search = new RegexSearch;
    }
    else
    {
        g_configuration->m_search = new RegularSearch;
    }

    g_configuration->m_search->setWholeWords(g_configuration->m_wholeWords);
    g_configuration->m_search->setCaseSensitive(g_configuration->m_ignoreCase);

    Search(g_configuration->m_searchText, g_configuration->m_files).run();

    delete g_configuration;

    return 0;
}