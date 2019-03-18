#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include "FileSystem/IFile.h"
#include "FileSystem/IDirectory.h"
#include "FileReader/IFileReader.h"
#include "Search/ISearch.h"
#include "Style/IStyle.h"
#include "ThreadPool/ThreadPool.h"
#include "Search/ExtensionMatch.h"

class Configuration
{
public:
    ~Configuration();
    static Configuration* getInstance();
private:
    Configuration();
public:
    size_t m_afterContext;
    size_t m_beforeContext;
    size_t m_context;
    bool   m_invertMatch;
    bool   m_ignoreCase;
    bool   m_recurse;

    IFile*       m_file;
    IDirectory*  m_directory;
    IFileReader* m_reader;
    ISearch*     m_search;
    IStyle*      m_style;
    ThreadPool*  m_threadPool;
    ExtensionMatch* m_extensionMatch;
    static Configuration* m_instance;
};

#endif // __CONFIGURATION_H__