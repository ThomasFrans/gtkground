#pragma once

#include <string>

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>

class InputPrompt : public Gtk::Window
{
public:
    InputPrompt();
    virtual ~InputPrompt();
    std::string* get_the_text();

protected:
    //Signal handlers:
    void on_button_confirm();

    //Child widgets:
    Gtk::Grid m_grid;
    Gtk::Label m_label;
    Gtk::Entry m_entry;
    Gtk::Button m_buttonConfirm;
    std::string* m_buffer;
};