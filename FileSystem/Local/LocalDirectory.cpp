#include <dirent.h>

#include "FileSystem/Local/LocalDirectory.h"

void LocalDirectory::open(const std::string& _directory)
{
    DIR* directory = opendir(_directory.c_str());

    if (!directory)
    {
        return;
    }

    struct dirent* file;

    while ((file = readdir(directory)) != 0)
    {
        std::string fileName = file->d_name;

        if (fileName != "." && fileName != "..")
        {
            m_files.push_back({ fileName, (file->d_type == DT_DIR) });
        }
    }

    closedir(directory);
}

std::vector<LocalDirectory::File>::const_iterator LocalDirectory::begin() const
{
    return m_files.begin();
}

std::vector<LocalDirectory::File>::const_iterator LocalDirectory::end() const
{
    return m_files.end();
}