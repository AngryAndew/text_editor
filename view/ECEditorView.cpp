#include "ECEditorView.h"
ECEditorView::ECEditorView() : x(0), y(0)
{}

void ECEditorView::refresh()
{
    view.Refresh();
}

void ECEditorView::update(const std::vector<std::string>&  lines)
{
    this->lines = lines;
    view.InitRows();
    view.AddRow("");
    for(int i = 0; i < lines.size(); i++)
    {
        view.AddRow(lines[i]);
    }
    refresh();
}

void ECEditorView::quit()
{
    view.Quit();
}

int ECEditorView::get_key()
{
    return view.GetPressedKey();
}

void ECEditorView::move_left()
{
    if (x - 1 >= 0 && x -1 <= lines[y].size())
    {
        view.SetCursorX(x -= 1);
    }
}

void ECEditorView::move_right()
{
    if (x + 1 >= 0 && x + 1 <= lines[y].size())
    {
        view.SetCursorX(x += 1);
    }
}

void ECEditorView::move_up()
{
    if (y - 1 >= 0 && y - 1 < lines.size())
    {
        view.SetCursorY(y -= 1);
    }
    if(x > lines[y].size())
    {
        view.SetCursorX(x = lines[y].size());
    }
    
}

void ECEditorView::move_down()
{
    if (y + 1 >= 0 && y + 1 < lines.size())
    {
        view.SetCursorY(y += 1);
    }
    if(x > lines[y].size())
    {
        view.SetCursorX(x = lines[y].size());
    }
}


void ECEditorView::attach(ECObserver* ob)
{
    view.Attach(ob);
}

void ECEditorView::show()
{
    view.Show();
}