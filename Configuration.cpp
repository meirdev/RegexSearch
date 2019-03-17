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

Configuration::~Configuration()
{
    delete m_threadPool;
    delete m_file;
    delete m_reader;
    delete m_search;
    delete m_style;
}