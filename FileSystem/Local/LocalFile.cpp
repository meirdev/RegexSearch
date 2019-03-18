#include <fstream>

#include "FileSystem/Local/LocalFile.h"

std::shared_ptr<char> LocalFile::getContent(const std::string& _fileName)
{
    std::ifstream file(_fileName, std::fstream::binary);

    file.seekg(0, std::ios_base::end);

    size_t fileSize = file.tellg();

    file.seekg(0, std::ios_base::beg);

    std::shared_ptr<char> m_buffer(new char[fileSize]);

    file.read(m_buffer.get(), fileSize);

    return m_buffer;
}