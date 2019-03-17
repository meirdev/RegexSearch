#include "FileSystem/ABCDirectory.h"

ABCDirectory::ABCDirectory(const std::string& _path)
: m_path(_path)
{
}

std::vector<IDirectory::File>::const_iterator ABCDirectory::begin() const
{
    return m_files.begin();
}

std::vector<IDirectory::File>::const_iterator ABCDirectory::end() const
{
    return m_files.end();
}

const std::string& ABCDirectory::getPath() const
{
    return m_path;
}