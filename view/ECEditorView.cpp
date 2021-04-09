#include "ECEditorView.h"
#include <iostream>
ECEditorView::ECEditorView() : x(0), y(0), pages{ECPage()}, active_page(0)
{
    pages[0].lines.push_back("");
    update_page(pages[0]);
}

void ECEditorView::refresh()
{
    view.Refresh();
}

void ECEditorView::update(const std::vector<std::string>&  lines)
{
    pages.clear();
    int i = 0;
    while (lines.size() - i > page_size())
    {
        ECPage page;
        for(int j = 0; j < page_size(); j++)
        {
            page.lines.push_back(lines[i + j]);
        }
        pages.push_back(page);
        i += page_size();
    }
    if (i < lines.size())
    {
        ECPage page;
        for(;i < lines.size(); i++)
        {
            page.lines.push_back(lines[i]);
        }
        pages.push_back(page);
    }
    if(active_page > pages.size())
    {
        active_page = pages.size() - 1;
    }
    update_page(pages[active_page]);
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
    int y = this->y % page_size();
    if (x - 1 >= 0 && x -1 <= pages[active_page].lines[y].size())
    {
        view.SetCursorX(x -= 1);
    }
     else if (x == 0)
     {
        if (this->y != 0)
        {
            move_up();
            move_end();
        }
     }
}

void ECEditorView::move_right()
{
    int y = this->y % page_size();
    if (x + 1 >= 0 && x + 1 <= pages[active_page].lines[y].size())
    {
        view.SetCursorX(x += 1);
    }

    else if(x == pages[active_page].lines[y].size())
    {
        if (this->y != (pages.size() - 1) * page_size() + pages.back().lines.size() - 1)
        {
        move_down();
        move_home();
        }
    }
}

void ECEditorView::move_up()
{
    int page_y = y % page_size();
    if (y - 1 >= 0)
    {
        view.SetCursorY((y -= 1) % page_size());
        if (page_y == 0)
        {
            active_page --;
            update_page(pages[active_page]);
        }
        
    }
    page_y = y % page_size();
    if(x > pages[active_page].lines[page_y].size())
    {
        view.SetCursorX(x = pages[active_page].lines[page_y].size());
    }
}

void ECEditorView::move_down()
{
    int page_y = y % page_size();
    if (y + 1 < (pages.size() - 1) * page_size() + pages.back().lines.size())
    {
        view.SetCursorY((y += 1) % page_size());
        if (page_y == page_size() - 1)
        {
            active_page ++;
            update_page(pages[active_page]);
        }
    }
    page_y = y % page_size();
    if(x > pages[active_page].lines[page_y].size())
    {
        view.SetCursorX(x = pages[active_page].lines[page_y].size());
    }
}

void ECEditorView::move_home()
{
    view.SetCursorX(x = 0);
}
void ECEditorView::move_end()
{
    view.SetCursorX(x = pages[active_page].lines[y % page_size()].size());
}


void ECEditorView::attach(ECObserver* ob)
{
    view.Attach(ob);
}

void ECEditorView::show()
{
    view.Show();
}

void ECEditorView::update_page(ECPage page)
{
    view.InitRows();
    view.AddRow("");
    for(int i = 0; i < page.lines.size(); i++)
    {
        view.AddRow(page.lines[i]);
    }
    refresh();
}

int ECEditorView::page_size()
{
    return view.GetRowNumInView() - 1;
}

int ECEditorView::page_at(int y)
{
    return y / page_size();
}