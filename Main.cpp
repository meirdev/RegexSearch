#include <iostream>
#include <getopt.h>

#include "Configuration.h"

#include "ThreadPool/ThreadPool.h"
#include "Search/RegularSearch/RegularSearch.h"
#include "Search/RegexSearch/RegexSearch.h"
#include "FileReader/Text/TextReader.h"
#include "FileSystem/Local/LocalFile.h"
#include "FileSystem/Local/LocalDirectory.h"
#include "Style/Ack/Ack.h"
#include "Runnable/Search.h"

Configuration* g_configuration;

int main(int argc, char** argv)
{
    std::string search;
    std::string files;

    if (argc == 1)
    {
        std::cout << "usage: ..." << std::endl;

        return 0;
    }

    if (argc > 1)
    {
        search = argv[1];
    }

    if (argc > 2)
    {
        files = argv[2];
    }
    else
    {
        files = ".";
    }

    g_configuration = Configuration::getInstance();

    g_configuration->m_file       = new LocalFile;
    g_configuration->m_directory  = new LocalDirectory;
    g_configuration->m_reader     = new TextReader;
    g_configuration->m_search     = new RegularSearch;
    g_configuration->m_style      = new Ack;
    g_configuration->m_threadPool = new ThreadPool(16);

    Search searchRunnable(search, files);

    searchRunnable.run();

    g_configuration->m_threadPool->shutdown(true);

    delete g_configuration;

    return 0;
}