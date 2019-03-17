#ifndef __FILE_SYSTEM_ABCDIRECTORY_H__
#define __FILE_SYSTEM_ABCDIRECTORY_H__

#include "FileSystem/IDirectory.h"

class ABCDirectory : public IDirectory
{
protected:
    ABCDirectory(const std::string& _path);
public:
    std::vector<File>::const_iterator begin() const;
    std::vector<File>::const_iterator end() const;
    const std::string& getPath() const;
protected:
    std::vector<File> m_files;
    std::string       m_path;
};

#endif // __FILE_SYSTEM_ABCDIRECTORY_H__