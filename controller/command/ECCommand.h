#ifndef ECCOMMAND_h
#define ECCOMMAND_h

class Command 
{
public:
virtual ~Command();
virtual void Execute() = 0;
//virtual void UnExecute() = 0;
protected:
Command();
};


#endif