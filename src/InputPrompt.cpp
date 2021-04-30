#include "InputPrompt.h"
#include <iostream>

InputPrompt::InputPrompt(std::string *buffer)
    : m_label("Enter the path to a Makefile"),
      m_buttonConfirm("Confirm")
{
    this->m_buffer = buffer;

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
    *m_buffer = m_entry.get_text();
    close();
}

InputPrompt::~InputPrompt()
{
}
