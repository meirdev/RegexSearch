#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include "FileSystem/IFile.h"
#include "FileSystem/IDirectory.h"
#include "FileReader/IFileReader.h"
#include "Search/ISearch.h"
#include "Style/IStyle.h"
#include "ThreadPool/ThreadPool.h"

class Configuration
{
public:
    ~Configuration();
    static Configuration* getInstance();
private:
    Configuration() = default;
public:
    IFile*       m_file;
    IDirectory*  m_directory;
    IFileReader* m_reader;
    ISearch*     m_search;
    IStyle*      m_style;
    ThreadPool*  m_threadPool;
    static Configuration* m_instance;
};

#endif // __CONFIGURATION_H__