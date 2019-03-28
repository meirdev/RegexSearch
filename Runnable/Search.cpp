#include "Runnable/Search.h"
#include "Runnable/FileReader.h"
#include "Search/ExtensionMatch.h"

Config* Search::m_config = nullptr;

Search::Search(const std::string& _search, const std::string& _files)
: m_search(_search)
, m_files(_files)
{
}

void Search::run()
{
    auto files = m_config->m_fileSystem->getDir()->getFiles(m_files);

    for (auto& i : files)
    {
        std::string fullPath = m_files + '/' + i.m_fileName;

        if (!i.m_isDirectory)
        {
            bool cond1 = (m_config->m_fileMatch == "") && m_config->m_extensionMatch.match(i.m_fileName);
            bool cond2 = (m_config->m_fileMatch != "") && m_config->m_extensionMatch.regexMatch(i.m_fileName, m_config->m_fileMatch);

            if (cond1 || cond2)
            {
                std::shared_ptr<IRunnable> file(new FileReader(m_search, fullPath));

                m_config->m_threadPool.submit(file);
            }
        }
        else if (m_config->m_recursive)
        {
            Search searchRunnable(m_search, fullPath);

            searchRunnable.run();
        }
    }
}