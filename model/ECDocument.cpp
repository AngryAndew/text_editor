#include "ECDocument.h"
#include <string>
#include <vector>
Document::Document(){}


void Document::insert(int x, int y, const std::string& str)
{
    lines[y].insert(x, str);
}
void Document::new_line(int x, int y)
{
    std::string str = lines[y].substr(x + 1, lines[y].size() - (x + 1));
    lines.insert(lines.begin() + y, str);
    lines[y] = lines[y].substr(0, x + 1);
}