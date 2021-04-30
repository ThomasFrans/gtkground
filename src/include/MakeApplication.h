#pragma once

#include <gtkmm/application.h>

class MakeApplication : public Gtk::Application
{
public:
    MakeApplication(int* argc, char** argv[]);
    virtual ~MakeApplication();
};