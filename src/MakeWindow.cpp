#include "MakeWindow.h"

MakeWindow::MakeWindow(const char *makeDir)
{
    this->m_makeDir = makeDir;
    m_css = Gtk::CssProvider::create();
    m_css->load_from_path("/home/thomas/Documents/Programming/gtkground/src/theme.css");

    std::string line;
    std::string makefilePath(m_makeDir);
    makefilePath.append("/Makefile");
    std::ifstream makefile(makefilePath);
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
                Gtk::Button *temp = new Gtk::Button(line);
                m_buttons.push_back(temp);
            }
        }
        makefile.close();
    }

    for (int i = 0; i < m_buttons.size(); i++)
    {
        m_buttons[i]->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MakeWindow::system_execute), m_buttons[i]->get_label()));
        m_flowBox.add(*m_buttons[i]);
        m_buttons[i]->show();
    }

    Glib::RefPtr<Gtk::StyleContext> ctx = get_style_context();
    ctx->add_provider_for_screen(Gdk::Screen::get_default(), m_css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); /*also tried different priorities*/

    set_icon_from_file("/home/thomas/Documents/Programming/gtkground/res/gnu_make.png");
    set_title("Make GUI");
    m_flowBox.set_max_children_per_line(1);
    m_flowBox.set_selection_mode(Gtk::SelectionMode::SELECTION_NONE);
    add(m_flowBox);
    m_flowBox.show();

    set_size_request(200, -1);
    present();
}

void MakeWindow::system_execute(std::string command)
{
    std::string program = "make -C ";
    program.append((std::string)m_makeDir);
    program.append(" ");
    program.append(command);
    system(program.c_str());
}

MakeWindow::~MakeWindow()
{
    for (Gtk::Button *button : m_buttons)
    {
        delete button;
    }
}