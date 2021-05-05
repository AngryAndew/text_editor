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
    if(mode == 0)
    {
        std::string str;
        str += static_cast<char>(key);
        history.execute(new InsertCommand(doc,view.x,view.y, str));
        move_right();
    }
    else
    {
        if(key != '/')
        {
            status += static_cast<char>(key);
            view.show_status_row(status);
        }
    }
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


    if (mode == 0)
    {
        if(view.x == 0)
        {
            if(view.y != 0)
            {
                int x = view.x;
                int y = view.y;
                move_up();
                move_end();
                history.execute(new Join_LineCommand(doc,x,y));
            }
            
        } 
        else
        {
            move_left();
            history.execute(new DeleteCommand(doc,view.x,view.y));
        }
    }
    else if (mode > 0)
    {
        if (status.size() > 0)
        {
            status.pop_back();
            view.show_status_row(status);
        }
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
    view.move_home(); 
    mode = 1; 
    view.show_status_row("");
}

void Controller::edit()
{
    mode = 0;
    view.kill_status_row();
    view.clear_color();
    view.move_home();  
}

void Controller::replace()
{
    mode = 2;
}

void Controller::highlight()
{
    if (status.size() == 0)
    {
        view.clear_color();
    }
    else
    {
        view.clear_color();
        std::vector<std::vector<int>> fives;
        fives = doc.find_string(status);
        for (int i = 0; i < fives[0].size(); i++)
        {
            view.change_color(fives[1][i] + 1, fives[0][i],  fives[0][i] + status.size() - 1); 
        }
        text = status;
    }
}

void Controller::replace_text(std::string text)
{
    history.execute(new Replace_LineCommand(doc,view.x, view.y, text, status));
    view.clear_color();
    view.refresh();
    search();
}

    