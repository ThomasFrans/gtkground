#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>

#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/grid.h>
#include <gtkmm/menubutton.h>
#include <gtkmm/builder.h>
#include <gtkmm/flowbox.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>

#include "InputPrompt.h"

const char* makeDir;

void system_execute(std::string command) {
    std::string program = "make -C ";
    program.append((std::string)makeDir);
    program.append(" ");
    program.append(command);
    // std::cout << makeDir << std::endl;
    // std::cout << program.c_str() << std::endl;
    system(program.c_str());
}

int main(int argc, char* argv[]) {

    auto app = Gtk::Application::create();
    Glib::RefPtr<Gtk::CssProvider> css = Gtk::CssProvider::create();
    css->load_from_path("/home/thomas/Documents/Programming/gtkground/src/theme.css");

    std::vector<Gtk::Button*> buttons;
    Gtk::Window window;
    Gtk::Grid grid;
    Gtk::FlowBox flowBox;

    std::string makefilePath;

    auto promptApp = Gtk::Application::create();
    if (argc == 1) {
        InputPrompt prompt;
        promptApp->run(prompt);
        makefilePath = *prompt.get_the_text();
    } else {
        makefilePath = std::string(argv[1]);
    }
    int folder = makefilePath.find_last_of("/");
    std::string makefileP = std::string(makefilePath);
    for (int i = folder; i < makefileP.size(); i++) {
        makefileP.erase(i);
    }
    makeDir = makefileP.c_str();
    // std::ofstream out("output.txt");
    // out << makeDir;
    // out.close();


    std::string line;
    std::ifstream makefile(makefilePath);
    if (makefile.is_open()) {
        while (std::getline(makefile, line))
        {
            if (line.find(":") != std::string::npos) {
                int pos = line.find(":");
                for (int i = pos; i < line.size(); i++) {
                    line.erase(i);
                }
                Gtk::Button* temp = new Gtk::Button(line);
                buttons.push_back(temp);
            }
        }
        makefile.close();
    }    
    
    Glib::RefPtr<Gtk::StyleContext> ctx = window.get_style_context();
    ctx->add_provider_for_screen(Gdk::Screen::get_default(), css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); /*also tried different priorities*/

    window.set_size_request(200, -1);
    window.set_title("Make GUI");
    window.set_icon_from_file("/home/thomas/Documents/Programming/gtkground/res/gnu_make.png");
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i]->signal_clicked().connect(sigc::bind(sigc::ptr_fun(&system_execute), buttons[i]->get_label()));
        flowBox.add(*buttons[i]);
        buttons[i]->show();
    }
    flowBox.set_selection_mode(Gtk::SelectionMode::SELECTION_NONE);
    flowBox.set_max_children_per_line(1);
    window.add(flowBox);
    flowBox.show();
    app->run(window);

    return 0;
}