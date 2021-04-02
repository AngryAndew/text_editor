#include "ECCommands.h"
InsertCommand::InsertCommand(Document& doc, int x, int y, std::string str): doc(doc), x(x), y(y), str(str){}
void InsertCommand::Execute()
{
    doc.insert(x, y, str);
}

New_LineCommand::New_LineCommand(Document& doc, int x, int y): doc(doc), x(x), y(y){}
void New_LineCommand::Execute()
{
    doc.new_line(x, y);
}