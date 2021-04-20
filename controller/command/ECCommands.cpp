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

DeleteCommand::DeleteCommand(Document& doc, int x, int y): doc(doc), x(x), y(y){}
void DeleteCommand::Execute()
{
    doc.del(x, y);
}

Join_LineCommand::Join_LineCommand(Document& doc, int x, int y): doc(doc), x(x), y(y){}
void Join_LineCommand::Execute()
{
    doc.join_line(x, y);
}

SaveCommand::SaveCommand(Document& doc, std::string filename): doc(doc), filename(filename){}
void SaveCommand::Execute()
{
    doc.save_file(filename);
}

LoadCommand::LoadCommand(Document& doc, std::string filename): doc(doc), filename(filename){}
void LoadCommand::Execute()
{
    doc.load_file(filename);
}

UndoCommand::UndoCommand(Document& doc, int x, int y): doc(doc), x(x), y(y){}
void UndoCommand::Execute()
{
    doc.undo(x,y);
}

RedoCommand::RedoCommand(Document& doc, int x, int y): doc(doc), x(x), y(y){}
void RedoCommand::Execute()
{
    doc.redo(x,y);;
}