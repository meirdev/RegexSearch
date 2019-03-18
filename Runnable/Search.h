#ifndef __RUNNABLE_SEARCH_H__
#define __RUNNABLE_SEARCH_H__

#include <string>

#include "ThreadPool/IRunnable.h"

class Search : public IRunnable
{
public:
    Search(const std::string& _search, const std::string& _files);
    void run();
private:
    std::string m_search;
    std::string m_files;
};

#endif // __RUNNABLE_SEARCH_H__