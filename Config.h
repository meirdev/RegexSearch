#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "ThreadPool/ThreadPool.h"
#include "Search/ISearch.h"
#include "FileSystem/IFileSystem.h"
#include "Style/IStyle.h"

class Config
{
public:
    ThreadPool   m_threadPool;
    ISearch*     m_searchEngine;
    IFileSystem* m_fileSystem;
    IStyle*      m_style;
    size_t       m_beforeContext;
    size_t       m_afterContext;
};

#endif // __CONFIG_H__