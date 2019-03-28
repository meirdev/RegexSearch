#include <iostream>
#include <queue>

#include "Runnable/FileReader.h"

Config* FileReader::m_config = nullptr;

FileReader::FileReader(const std::string& _search, const std::string& _file)
: m_search(_search)
, m_file(_file)
{
}

void FileReader::run()
{
    IFile* file = m_config->m_fileSystem->getFile();

    std::string output;

    size_t countResults = 0;

    try
    {
        file->open(m_file);

        std::string buffer;

        size_t lineNumber = 1, bI = 0, aI = 0;

        std::queue<std::pair<size_t, std::string>> lines;

        auto readFromQueue = [&]{
            while (!lines.empty())
            {
                auto front = lines.front();

                output += m_config->m_style->lineNumber(front.first) + "- " + m_config->m_style->line(front.second) + "\n";
                
                lines.pop();
            }
        };

        while (file->read(buffer))
        {
            auto results = m_config->m_searchEngine->search(m_search, buffer);

            size_t nResults = results.size();

            if (nResults)
            {
                countResults += nResults;

                readFromQueue();

                bI = 0;
                aI = m_config->m_afterContext;

                output += m_config->m_style->lineNumber(lineNumber) + ": " + m_config->m_style->line(buffer, results) + "\n";
            }
            else
            {
                lines.push({ lineNumber, buffer });

                if (bI == m_config->m_beforeContext && aI == 0)
                {
                    lines.pop();

                    --bI;
                }

                ++bI;

                if (aI > 0)
                {
                    --aI;

                    if (aI == 0)
                    {
                        readFromQueue();

                        bI = 0;
                    }
                }
            }

            ++lineNumber;
        }
    }
    catch (...)
    {

    }

    if (countResults)
    {
        output = m_config->m_style->fileName(m_file) + "\n" + output;

        std::cout << output;
    }

    delete file;
}