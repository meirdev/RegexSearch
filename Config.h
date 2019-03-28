#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>

#include "ThreadPool/ThreadPool.h"
#include "Search/ExtensionMatch.h"
#include "Search/ISearch.h"
#include "FileSystem/IFileSystem.h"
#include "Style/IStyle.h"

class Config
{
public:
    ThreadPool     m_threadPool;
    ExtensionMatch m_extensionMatch;
    ISearch*       m_searchEngine;
    IFileSystem*   m_fileSystem;
    IStyle*        m_style;
    size_t         m_beforeContext;
    size_t         m_afterContext;
    std::string    m_fileMatch;
    bool           m_recursive;
};

#endif // __CONFIG_H__