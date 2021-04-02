#include "ECController.h"
#include "ECCommands.h"
Controller::Controller() : view(), doc(view)
{}

void Controller::new_line()
{
    New_LineCommand(doc,view.x,view.y).Execute();
    move_down();
    //todo: make move home
    while (view.x != 0)
    {
        move_left();
    }
}

void Controller::quit()
{
    view.quit();
}

int Controller::get_key()
{
    return view.get_key();
}

void Controller::move_left()
{
    view.move_left();
}

void Controller::move_right()
{
    view.move_right();
}

void Controller::move_up()
{
    view.move_up();
}

void Controller::move_down()
{
    view.move_down();
}

void Controller::type(int key)
{
    std::string str;
    str += static_cast<char>(key);
    InsertCommand(doc,view.x,view.y, str).Execute();
    move_right();
}

void Controller::attach(ECObserver* ob)
{
    view.attach(ob);
}

void Controller::show()
{
    view.show();
}