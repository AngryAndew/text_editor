#include "ECController.h"
#include "ECCommands.h"
Controller::Controller(std::string filename) : view(), doc(view), filename(filename)
{
    view.refresh();
    LoadCommand(doc, filename).Execute();
}

void Controller::new_line()
{
    New_LineCommand(doc,view.x,view.y).Execute();
    move_down();
    move_home();
}

void Controller::quit()
{
    SaveCommand(doc, filename).Execute();
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

void Controller::move_home()
{
    view.move_home();
}

void Controller::move_end()
{
    view.move_end();
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

void Controller::del()
{
    if(view.x == 0)
    {
        int x = view.x;
        int y = view.y;
        move_up();
        move_end();
        Join_LineCommand(doc,x,y).Execute();
    } 
    else
    {
        move_left();
        DeleteCommand(doc,view.x,view.y).Execute();
    }
}