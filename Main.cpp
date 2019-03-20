#include "CLI11.hpp"
#include "Configuration.h"
#include "Runnable/Search.h"

Configuration* g_configuration;

int main(int argc, char** argv)
{
    g_configuration = Configuration::getInstance();

    CLI::App app("Search");

    app.add_option("search",   g_configuration->m_searchText, "Text to search")->required();
    app.add_option("files",    g_configuration->m_files, "Search in directroy");
    app.add_option("--before", g_configuration->m_beforeContext, "Lines before result");
    app.add_option("--after",  g_configuration->m_afterContext, "Lines after result");

    app.add_flag("--onlyFilename", g_configuration->m_onlyFilename, "Show only file name without matchs");
    app.add_flag("--inlineFilename", g_configuration->m_inlineFilename, "Show file name in same line with match");
    app.add_flag("--allFiles", g_configuration->m_allFiles, "Show all files");

    CLI11_PARSE(app, argc, argv);

    Search(g_configuration->m_searchText, g_configuration->m_files).run();

    delete g_configuration;

    return 0;
}