#include "ECCommands.h"
InsertCommand::InsertCommand(Document& doc, int x, int y, std::string str): doc(doc), x(x), y(y), str(str){}
void InsertCommand::Execute()
{
    doc.insert(x, y, str);
}

void InsertCommand::UnExecute()
{
    doc.del(x, y);
}

New_LineCommand::New_LineCommand(Document& doc, int x, int y): doc(doc), x(x), y(y){}
void New_LineCommand::Execute()
{
    doc.new_line(x, y);
}

void New_LineCommand::UnExecute()
{
    doc.join_line(0, y + 1);
}

DeleteCommand::DeleteCommand(Document& doc, int x, int y): doc(doc), x(x), y(y){}
void DeleteCommand::Execute()
{
   this->c = doc.del(x, y);
}

void DeleteCommand::UnExecute()
{
    doc.insert(x, y, std::string(1, c));
}

Join_LineCommand::Join_LineCommand(Document& doc, int x, int y): doc(doc), x(x), y(y){}
void Join_LineCommand::Execute()
{
   this->px = doc.join_line(x, y);
}

void Join_LineCommand::UnExecute()
{
    doc.new_line(px, y - 1);
}

SaveCommand::SaveCommand(Document& doc, std::string filename): doc(doc), filename(filename){}
void SaveCommand::Execute()
{
    doc.save_file(filename);
}

void SaveCommand::UnExecute()
{}

LoadCommand::LoadCommand(Document& doc, std::string filename): doc(doc), filename(filename){}
void LoadCommand::Execute()
{
    doc.load_file(filename);
}

void LoadCommand::UnExecute()
{}
