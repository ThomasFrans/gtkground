#pragma once

#include <string>

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <gtkmm/application.h>
#include <gtkmm/cssprovider.h>

class InputPrompt : public Gtk::Window
{
public:
    InputPrompt(std::string *buffer);
    virtual ~InputPrompt();

private:
    /* Excecute on pressing the confirm button. */
    void on_button_confirm();

    //Child widgets:
    Glib::RefPtr<Gtk::Application> m_app;
    Gtk::Grid m_grid;
    Glib::RefPtr<Gtk::CssProvider> m_css;
    Gtk::Label m_label;
    Gtk::Entry m_entry;
    Gtk::Button m_buttonConfirm;
    std::string *m_buffer;
};