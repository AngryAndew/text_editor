#include "ECObservers.h"
 
Quit_Ob::Quit_Ob(Controller& control) : control(control){}

void Quit_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::CTRL_Q)
    {
       control.quit();
    }
}

New_Line_Ob::New_Line_Ob(Controller& control) : control(control){}

void New_Line_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::ENTER)
    {
       control.new_line();
    }
}
//put into handler if time 
Move_Left_Ob::Move_Left_Ob(Controller& control) : control(control){}

void Move_Left_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::ARROW_LEFT)
    {
       control.move_left();
    }
}

Move_Right_Ob::Move_Right_Ob(Controller& control) : control(control){}

void Move_Right_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::ARROW_RIGHT)
    {
       control.move_right();
    }
}

Move_Up_Ob::Move_Up_Ob(Controller& control) : control(control){}

void Move_Up_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::ARROW_UP)
    {
       control.move_up();
    }
}

Move_Down_Ob::Move_Down_Ob(Controller& control) : control(control){}

void Move_Down_Ob::Update()
{
    if (control.get_key() == KEY_ACTION::ARROW_DOWN)
    {
       control.move_down();
    }
}


Typing_Ob::Typing_Ob(Controller& control) : control(control){}
void Typing_Ob::Update()
{
    int key = control.get_key();
    if (key >= 32 && key <= 126)
    {
       control.type(key);
    }
}

Delete_Ob::Delete_Ob(Controller& control) : control(control){}
void Delete_Ob::Update()
{
    int key = control.get_key();
    if (key == KEY_ACTION::BACKSPACE)
    {
       control.del();
    }
}
