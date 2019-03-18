#include "Configuration.h"

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
{
    m_extensionMatch = new ExtensionMatch;

    m_extensionMatch->add("c");
    m_extensionMatch->add("cpp");
    m_extensionMatch->add("h");
    m_extensionMatch->add("hpp");
}

Configuration::~Configuration()
{
    delete m_directory;
    delete m_threadPool;
    delete m_file;
    delete m_reader;
    delete m_search;
    delete m_style;
    delete m_extensionMatch;
}