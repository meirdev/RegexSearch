#include "Runnable/Search.h"
#include "FileSystem/Local/LocalDirectory.h"
#include "Runnable/File.h"
#include "Configuration.h"
#include "Search/FilenameMatch.h"

extern Configuration* g_configuration;

Search::Search(const std::string& _search, const std::string& _files, size_t _level)
: m_search(_search)
, m_files(_files)
, m_level(_level)
{
}

void Search::run()
{
    IDirectory* directory = new LocalDirectory(m_files);

    for (auto& i : *directory)
    {
        std::string fullPath = m_files + '/' + i.m_fileName;

        if (!i.m_isDirectory)
        {
            if (FilenameMatch::matchByExtension(i.m_fileName, "h") || FilenameMatch::matchByExtension(i.m_fileName, "cpp")  || FilenameMatch::matchByExtension(i.m_fileName, "t"))
            {
                std::shared_ptr<IRunnable> file(new File(m_search, fullPath));

                g_configuration->m_threadPool->submit(file);
            }
        }
        else
        {
            Search searchRunnable(m_search, fullPath, m_level+1);

            searchRunnable.run();
        }
    }
}

Search::~Search()
{
    if (m_level == 0)
    {
        g_configuration->m_threadPool->shutdown(true);
    }
}