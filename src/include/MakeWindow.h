#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/flowbox.h>
#include <gtkmm/cssprovider.h>

class MakeWindow : public Gtk::Window
{
public:
    MakeWindow(const char* makeDir);
    virtual ~MakeWindow();
private:
    void system_execute(std::string command);

    std::vector<Gtk::Button *> m_buttons;
    Gtk::Grid m_grid;
    Gtk::FlowBox m_flowBox;
    Glib::RefPtr<Gtk::CssProvider> m_css;
    const char* m_makeDir;
};