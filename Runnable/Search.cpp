#include "Runnable/Search.h"
#include "FileSystem/Local/LocalDirectory.h"
#include "Runnable/File.h"
#include "Configuration.h"

extern Configuration* g_configuration;

Search::Search(const std::string& _search, const std::string& _files)
: m_search(_search)
, m_files(_files)
{
}

void Search::run()
{
    auto files = g_configuration->m_directory->getFiles(m_files);

    for (auto& i : files)
    {
        std::string fullPath = m_files + '/' + i.m_fileName;

        if (!i.m_isDirectory)
        {
            if (g_configuration->m_extensionMatch->match(i.m_fileName))
            {
                std::shared_ptr<IRunnable> file(new File(m_search, fullPath));

                g_configuration->m_threadPool->submit(file);
            }
        }
        else
        {
            Search searchRunnable(m_search, fullPath);

            searchRunnable.run();
        }
    }
}