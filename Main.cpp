#include <iostream>

#include "Configuration.h"
#include "Runnable/Search.h"

Configuration* g_configuration;

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout << "usage: ..." << std::endl;

        return 0;
    }

    g_configuration = Configuration::getInstance(argc, argv);

    Search(g_configuration->m_searchText, g_configuration->m_files).run();

    delete g_configuration;

    return 0;
}