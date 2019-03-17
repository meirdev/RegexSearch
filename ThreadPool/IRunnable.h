#ifndef __IRUNNABLE_H__
#define __IRUNNABLE_H__

class IRunnable
{
public:
    virtual ~IRunnable() = default;
    virtual void run() = 0;
};

#endif // __RUNNABLE_H__