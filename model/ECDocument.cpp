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

void Document::update()
{
    view.update(lines);
}