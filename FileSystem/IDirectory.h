#ifndef __FILE_SYSTEM_IDIRECTORY_H__
#define __FILE_SYSTEM_IDIRECTORY_H__

#include <string>
#include <vector>

class IDirectory
{
public:
    typedef struct
    {
        std::string m_fileName;
        bool        m_isDirectory;
    } File;
public:
    virtual ~IDirectory() = default;
    virtual void open(const std::string& _directory) = 0;
    virtual std::vector<File>::const_iterator begin() const = 0;
    virtual std::vector<File>::const_iterator end() const = 0;
};

#endif // __FILE_SYSTEM_IDIRECTORY_H__