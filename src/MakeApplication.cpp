#include "MakeApplication.h"

#include <string>

#include "InputPrompt.h"
#include "MakeWindow.h"

MakeApplication::MakeApplication(int *argc, char **argv[])
{
    std::string makefilePath;
    const char* makefileDir;

    if (*argc == 1)
    {
        InputPrompt prompt(&makefilePath);
    }
    else
    {
        makefilePath = std::string((*argv)[1]);
    }
        
    int folder = makefilePath.find_last_of("/");
    std::string makefileP = std::string(makefilePath);
    for (int i = folder; i < makefileP.size(); i++)
    {
        makefileP.erase(i);
    }
    makefileDir = makefileP.c_str();

    MakeWindow window(makefileDir);
}

MakeApplication::~MakeApplication()
{
}
