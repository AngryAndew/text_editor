#include "ECCommand.h"

Command::Command(){}
Command::~Command(){}

CommandHistory::~CommandHistory()
{
    for (int i = 0; i < this->history.size(); i++)
    {
        delete history[i];
    }
}
    
void CommandHistory::execute(Command* command)
{
    command->Execute();
    undid.clear();
    history.push_back(command);
}
void CommandHistory::undo()
{
    if(history.size() != 0)
    {
        undid.push_back(this->history.back());
        this->history.pop_back();
        undid.back()->UnExecute();
    }
}
void CommandHistory::redo()
{
    if (undid.size() != 0)
    {
        this->history.push_back(undid.back());
        undid.pop_back();
        this->history.back()->Execute();
    } 
}
    
    