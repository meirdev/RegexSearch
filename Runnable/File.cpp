#include <iostream>

#include "Runnable/File.h"
#include "Configuration.h"

extern Configuration* g_configuration;

File::File(const std::string& _search, const std::string& _file)
: m_search(_search)
, m_file(_file)
{
}

void File::run()
{
    std::shared_ptr<char> content = g_configuration->m_file->getContent(m_file);
    const std::string&  read      = g_configuration->m_reader->read(content);
    const SearchResult& results   = g_configuration->m_search->search(m_search, read);
    const std::string&  view      = g_configuration->m_style->result(m_file, read, results);

    std::cout << view;
}