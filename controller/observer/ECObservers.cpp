#include "ECObservers.h"
 
Quit_Ob::Quit_Ob(Controller& control) : control(control){}

void Quit_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::CTRL_Q )
    {
       control.quit();
    }
}

New_Line_Ob::New_Line_Ob(Controller& control) : control(control){}

void New_Line_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::ENTER && control.mode == 0)
    {
       control.new_line();
    }
    else if (control.get_key() == KEY_ACTION::ENTER && control.mode == 1)
    {
       control.highlight();
    }
    else if (control.get_key() == KEY_ACTION::ENTER && control.mode == 2)
    {
       control.replace_text(control.text);
    }
}
//put into handler if time 
Move_Left_Ob::Move_Left_Ob(Controller& control) : control(control){}

void Move_Left_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::ARROW_LEFT && control.mode == 0)
    {
       control.move_left();
    }
}

Move_Right_Ob::Move_Right_Ob(Controller& control) : control(control){}

void Move_Right_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::ARROW_RIGHT && control.mode == 0)
    {
       control.move_right();
    }
}

Move_Up_Ob::Move_Up_Ob(Controller& control) : control(control){}

void Move_Up_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::ARROW_UP && control.mode == 0)
    {
       control.move_up();
    }
}

Move_Down_Ob::Move_Down_Ob(Controller& control) : control(control){}

void Move_Down_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::ARROW_DOWN && control.mode == 0)
    {
       control.move_down();
    }
}


Typing_Ob::Typing_Ob(Controller& control) : control(control){}
void Typing_Ob::Update()
{
    int key = control.get_key();
    if (key >= 32 && key <= 126 && control.mode == 0)
    {
       control.type(key);
    }
    else if (key >= 32 && key <= 126 && control.mode > 0)
    {
       control.type(key);
    }
}

Delete_Ob::Delete_Ob(Controller& control) : control(control){}
void Delete_Ob::Update()
{
    int key = control.get_key();
    if (key == KEY_ACTION::BACKSPACE && control.mode == 0)
    {
       control.del();
    }
    else if (key == KEY_ACTION::BACKSPACE && control.mode > 0)
    {
       control.del();
    }
}

Undo_Ob::Undo_Ob(Controller& control) : control(control){}
void Undo_Ob::Update()
{
    int key = control.get_key();
    if (key == KEY_ACTION::CTRL_Z && control.mode == 0)
    {
       control.undo();
    }
}

Redo_Ob::Redo_Ob(Controller& control) : control(control){}
void Redo_Ob::Update()
{
    int key = control.get_key();
    if (key == KEY_ACTION::CTRL_Y && control.mode == 0)
    {
       control.redo();
    }
}

Search_Ob::Search_Ob(Controller& control) : control(control){}
void Search_Ob::Update()
{
    int key = control.get_key();
    if (key == KEY_ACTION::CTRL_F && control.mode == 0)
    {
       control.search();
    }
}

Quit_Mode_Ob::Quit_Mode_Ob(Controller& control) : control(control){}
void Quit_Mode_Ob::Update()
{
    int key = control.get_key();
    if (key == KEY_ACTION::ESC && control.mode == 1)
    {
       control.edit();
    }
    else if (key == KEY_ACTION::ESC && control.mode == 2)
    {
       control.search();
    }
}

Replace_Ob::Replace_Ob(Controller& control) : control(control){}
void Replace_Ob::Update()
{
    int key = control.get_key();
    if (key == '/' && control.mode == 1)
    {
       control.replace();
    }
}
