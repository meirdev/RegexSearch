#ifndef __RUNNABLE_FILE_READER_H__
#define __RUNNABLE_FILE_READER_H__

#include <string>

#include "Config.h"
#include "ThreadPool/IRunnable.h"

class FileReader : public IRunnable
{
public:
    FileReader(const std::string& _search, const std::string& _file);
    void run();
public:
    static Config* m_config;
private:
    std::string m_search;
    std::string m_file;
};

#endif // __RUNNABLE_FILE_READER_H__