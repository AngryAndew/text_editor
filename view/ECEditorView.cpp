#include "ECEditorView.h"

void ECEditorView::refresh()
{
    view.Refresh();
}

void ECEditorView::update()
{
    view.InitRows();
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
    view.GetPressedKey();
}

void ECEditorView::move_left()
{
    if (x - 1 >= 0 && x -1 < lines[y].size())
        {
            view.SetCursorX(x - 1);
        }
}

void ECEditorView::move_right()
{
    if (x + 1 >= 0 && x + 1 < lines[y].size())
        {
            view.SetCursorX(x + 1);
        }
}

void ECEditorView::move_up()
{
    if (y - 1 >= 0 && y - 1 < lines.size())
            {
                view.SetCursorY(y - 1);
            }
}

void ECEditorView::move_down()
{
    if (y + 1 >= 0 && y + 1 < lines.size())
        {
            view.SetCursorY(y + 1);
        }
}