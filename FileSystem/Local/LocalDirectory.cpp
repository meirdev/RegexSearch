#include <stdexcept>

#include "FileSystem/Local/LocalDirectory.h"

LocalDirectory::LocalDirectory(const std::string& _directory)
: ABCDirectory(_directory)
{
    m_directory = opendir(_directory.c_str());

    if (!m_directory)
    {
        throw std::runtime_error("can't open dir.");
    }

    struct dirent* file;

    while ((file = readdir(m_directory)) != 0)
    {
        std::string fileName = file->d_name;

        if (fileName != "." && fileName != "..")
        {
            m_files.push_back({ fileName, (file->d_type == DT_DIR) });
        }
    }
}

LocalDirectory::~LocalDirectory()
{
    closedir(m_directory);
}