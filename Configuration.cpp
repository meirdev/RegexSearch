#include "Configuration.h"
#include "Search/RegularSearch/RegularSearch.h"
#include "Search/RegexSearch/RegexSearch.h"
#include "FileReader/Text/TextReader.h"
#include "FileSystem/Local/LocalFile.h"
#include "FileSystem/Local/LocalDirectory.h"
#include "Style/Ack/Ack.h"

Configuration* Configuration::m_instance = nullptr;

Configuration* Configuration::getInstance()
{
    if (!m_instance)
    {
        m_instance = new Configuration;
    }

    return m_instance;
}

Configuration::Configuration()
: m_files(".")
, m_beforeContext(0)
, m_afterContext(0)
, m_onlyFilename(false)
, m_inlineFilename(false)
, m_allFiles(false)
{
    m_extensionMatch = new ExtensionMatch;

    m_file       = new LocalFile;
    m_directory  = new LocalDirectory;
    m_reader     = new TextReader;
    m_search     = new RegularSearch;
    m_style      = new Ack;
    m_threadPool = new ThreadPool;
}

Configuration::~Configuration()
{
    m_threadPool->shutdown(true);

    delete m_threadPool;
    delete m_directory;
    delete m_file;
    delete m_reader;
    delete m_search;
    delete m_style;
    delete m_extensionMatch;
}