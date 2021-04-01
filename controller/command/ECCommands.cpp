#include "ECCommands.h"

void InsertCommand::Execute(int x, int y, std::string str)
{
    doc.insert(x, y, str);
}

void New_LineCommand::Execute(int x, int y)
{
    doc.new_line(x, y);
}