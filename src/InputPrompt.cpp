#include "InputPrompt.h"
#include <iostream>

InputPrompt::InputPrompt()
: m_label("Enter the path to a Makefile"),
m_buttonConfirm("Confirm")
{
    set_title("Makefile path");

    add(this->m_grid);

    m_grid.attach(m_label, 0, 0, 2, 1);
    m_grid.attach(m_entry, 0, 1);
    m_grid.attach(m_buttonConfirm, 1, 1);

    m_buttonConfirm.signal_clicked().connect(sigc::mem_fun(*this, &InputPrompt::on_button_confirm));

    m_label.show();
    m_entry.show();
    m_buttonConfirm.show();
    m_grid.show();
    present();
}

void InputPrompt::on_button_confirm()
{
    close();
}

std::string* InputPrompt::get_the_text()
{
    
    return new std::string(m_entry.get_text());
}

InputPrompt::~InputPrompt()
{

}
