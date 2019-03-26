#include "FileSystem/Local/LocalFile.h"

void LocalFile::open(const std::string& _fileName)
{
    m_file.open(_fileName);
}

void LocalFile::close()
{
}

bool LocalFile::read(std::string& _buffer)
{
    if (m_file.eof())
    {
        return false;
    }

    getline(m_file, _buffer);

    return true;
}