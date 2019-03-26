#ifndef __FILE_SYSTEM_IFILE_H__
#define __FILE_SYSTEM_IFILE_H__

#include <string>

class IFile
{
public:
    virtual ~IFile() = default;
    virtual void open(const std::string& _fileName) = 0;
    virtual void close() = 0;
    virtual bool read(std::string& _buffer) = 0;
};

#endif // __FILE_SYSTEM_IFILE_H__