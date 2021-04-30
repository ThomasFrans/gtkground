#pragma once

#include <string>
#include <vector>

class MakefileParser
{
public:
    MakefileParser(const char* path);
    ~MakefileParser();
    void getTargets(std::vector<std::string>* targets);
private:
    const char* m_path;
};
