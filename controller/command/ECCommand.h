#ifndef ECCOMMAND_h
#define ECCOMMAND_h
#include <vector>
class Command 
{
public:
virtual ~Command();
virtual void Execute() = 0;
virtual void UnExecute() = 0;
protected:
Command();
};

class CommandHistory	
{	
public:
    ~CommandHistory();
   
    void execute(Command* command);
    void undo();
    void redo();
private:
    std::vector<Command*> history;
    std::vector<Command*> undid;
};
#endif