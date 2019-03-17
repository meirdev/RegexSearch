#ifdef __WAITABLE_QUEUE_H__

template<class T>
void WaitableQueue<T>::push(const T& _value)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    m_queue.push(_value);

    m_conditionVariable.notify_all();
}

template<class T>
void WaitableQueue<T>::pop(T& _value)
{
    std::unique_lock<std::mutex> lock(m_mutex);

    while (m_queue.empty())
    {
        m_conditionVariable.wait(lock);
    }

    _value = m_queue.front();

    m_queue.pop();
}

template<class T>
size_t WaitableQueue<T>::size()
{
    std::lock_guard<std::mutex> lock(m_mutex);

    return m_queue.size();
}

template<class T>
bool WaitableQueue<T>::empty()
{
    std::lock_guard<std::mutex> lock(m_mutex);

    return m_queue.empty();
}

#endif // __WAITABLE_QUEUE_H__