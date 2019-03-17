#include <fstream>

#include "FileSystem/Local/LocalFile.h"

LocalFile::~LocalFile()
{
    delete[] m_buffer;
}

char* LocalFile::getContent(const std::string& _fileName)
{
    std::ifstream file(_fileName, std::fstream::binary);

    file.seekg(0, std::ios_base::end);

    size_t fileSize = file.tellg();

    file.seekg(0, std::ios_base::beg);

    m_buffer = new char[fileSize];

    file.read(m_buffer, fileSize);

    return m_buffer;
}