#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>

#include <gtkmm/application.h>

#include "InputPrompt.h"
#include "MakeWindow.h"


int main(int argc, char *argv[])
{

    const char *makeDir;
    std::string makefilePath;

    auto promptApp = Gtk::Application::create();
    if (argc == 1)
    {
        InputPrompt prompt(&makefilePath);
        promptApp->run(prompt);
    }
    else
    {
        makefilePath = std::string(argv[1]);
    }
    int folder = makefilePath.find_last_of("/");
    std::string makefileP = std::string(makefilePath);
    for (int i = folder; i < makefileP.size(); i++)
    {
        makefileP.erase(i);
    }
    makeDir = makefileP.c_str();

    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create();
    MakeWindow window(makeDir);
    app->run(window);

    return 0;
}