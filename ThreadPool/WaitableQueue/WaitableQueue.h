#ifndef __WAITABLE_QUEUE_H__
#define __WAITABLE_QUEUE_H__

#include <queue>
#include <mutex>
#include <condition_variable>

template<class T>
class WaitableQueue
{
public:
    void push(const T& _value);
    void pop(T& _value);
    size_t size();
    bool empty();
private:
    std::queue<T> m_queue;
    std::mutex    m_mutex;
    std::condition_variable m_conditionVariable;
};

#include "ThreadPool/WaitableQueue/WaitableQueue.hpp"

#endif // __WAITABLE_QUEUE_H__