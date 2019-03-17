#ifndef __RUNNABLE_SEARCH_H__
#define __RUNNABLE_SEARCH_H__

#include <string>

#include "ThreadPool/IRunnable.h"

class Search : public IRunnable
{
public:
    Search(const std::string& _search, const std::string& _files, size_t _level = 0);
    ~Search();
    void run();
private:
    std::string m_search;
    std::string m_files;
    size_t      m_level;
};

#endif // __RUNNABLE_SEARCH_H__