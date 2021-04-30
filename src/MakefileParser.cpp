#include "MakefileParser.h"

#include <fstream>
#include <vector>

MakefileParser::MakefileParser(const char* path)
{
    this->m_path=path;
}

MakefileParser::~MakefileParser()
{

}

void MakefileParser::getTargets(std::vector<std::string>* targets)
{
    std::string line;
    std::ifstream makefile(m_path);
    if (makefile.is_open())
    {
        while (std::getline(makefile, line))
        {
            if (line.find(":") != std::string::npos)
            {
                int pos = line.find(":");
                for (int i = pos; i < line.size(); i++)
                {
                    line.erase(i);
                }
                targets->push_back(line.c_str());
            }
        }
        makefile.close();
    }
    
}
