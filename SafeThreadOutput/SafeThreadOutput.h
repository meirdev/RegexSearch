#ifndef __SAFE_THREAD_OUTPUT_H__
#define __SAFE_THREAD_OUTPUT_H__

#include <string>
#include <mutex>

class SafeThreadOutput
{
public:
    void operator<<(const std::string& _string);
private:
    std::mutex m_mutex;
};

#endif // __SAFE_THREAD_OUTPUT_H__