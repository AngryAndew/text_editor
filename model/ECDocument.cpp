#include "ECDocument.h"
#include <string>
#include <vector>

Document::Document(ECEditorView& view) : view(view), lines{""}
{}


void Document::insert(int x, int y, const std::string& str)
{
    lines[y].insert(x, str);
    update();
}
void Document::new_line(int x, int y)
{
    std::string str = lines[y].substr(x);
    lines.insert(lines.begin() + y + 1, str);
    lines[y] = lines[y].substr(0, x);
    update();
}

void Document::del(int x, int y)
{
    lines[y].erase(lines[y].begin() + (x));
    update();
}

void Document::join_line(int x, int y)
{
    if(y > 0)
    {
        lines[y - 1] += lines[y];
        lines.erase(lines.begin() + y);
        update();
    }
}

void Document::update()
{
    view.update(lines);
}

int Document::line_size(int y)
{
    return lines[y].size();
}