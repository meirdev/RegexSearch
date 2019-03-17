#include <iostream>

#include "ThreadPool/ThreadPool.h"

ThreadPool::ThreadPool(size_t _nThreads)
: m_running(true)
, m_gracefulShutdown(false)
{
    for (size_t i = 0; i < _nThreads; ++i)
    {
        m_threads.push_back(std::thread([this]
        {
            while (static_cast<bool>(m_running) || (m_gracefulShutdown && !m_queue.empty()))
            {
                std::shared_ptr<IRunnable> runnable;

                m_queue.pop(runnable);

                if (runnable.get() == nullptr)
                {
                    break;
                }

                runnable->run();
            }
        }));
    }
}

ThreadPool::~ThreadPool()
{
    for (auto& thread : m_threads)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }
}

void ThreadPool::submit(std::shared_ptr<IRunnable> _task)
{
    if (static_cast<bool>(m_running))
    {
        m_queue.push(_task);
    }
}

void ThreadPool::shutdown(bool _graceful)
{
    m_running = false;
    m_gracefulShutdown = _graceful;

    std::shared_ptr<IRunnable> stop(nullptr);

    for (size_t i = 0, nThreads = m_threads.size(); i < nThreads; ++i)
    {
        m_queue.push(stop);
    }
}