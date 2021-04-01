#include "ECController.h"
Controller::Controller(ECEditorView view, Document doc) : view(view), doc(doc){}

void Controller::insert()
{
    doc.insert();
}

void Controller::new_line()
{
    doc.new_line();
}

void Controller::quit()
{
    view.quit();
}

int Controller::get_key()
{
    view.get_key();
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

