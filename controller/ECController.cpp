#include "ECController.h"
#include "ECCommands.h"
Controller::Controller(std::string filename, int mode) : view(), doc(view), filename(filename), mode(mode)
{
    view.refresh();
    LoadCommand(doc,filename).Execute();
}

void Controller::new_line()
{
    history.execute(new New_LineCommand(doc,view.x,view.y));
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
    history.execute(new InsertCommand(doc,view.x,view.y, str));
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
        history.execute(new Join_LineCommand(doc,x,y));
    } 
    else
    {
        move_left();
        history.execute(new DeleteCommand(doc,view.x,view.y));
    }
}

void Controller::undo()
{
    history.undo();
    if(!vaild_cursor())
    {
        move_valid_cursor();
    }
}

void Controller::redo()
{
    history.redo();
    if(!vaild_cursor())
    {
        move_valid_cursor();
    }
}

bool Controller::vaild_cursor()
{
   return view.y >= 0 && view.y < doc.total_lines() && view.x >= 0 && view.x <= doc.line_size(view.y);   
}

void Controller::move_valid_cursor()
{
    if (view.y >= doc.total_lines())
    {
        view.set_y(doc.total_lines() - 1);
    }
    if (view.x > doc.line_size(view.y))
    {
        view.set_x(doc.line_size(view.y));
    }
}

void Controller::search()
{
    mode = 1;   
}

void Controller::edit()
{
    mode = 0;   
}

void Controller::replace()
{
    mode = 2;   
}
    