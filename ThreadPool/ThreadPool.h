#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <vector>
#include <thread>
#include <atomic>

#include "ThreadPool/WaitableQueue/WaitableQueue.h"
#include "ThreadPool/IRunnable.h"

class ThreadPool
{
public:
    ThreadPool(size_t _nThreads);
    ~ThreadPool();
    void submit(std::shared_ptr<IRunnable> _task);
    void shutdown(bool _graceful = false);
private:
    WaitableQueue<std::shared_ptr<IRunnable>> m_queue;
    std::vector<std::thread> m_threads;
    std::atomic<bool> m_running;
    std::atomic<bool> m_gracefulShutdown;
};

#endif // __THREAD_POOL_H__