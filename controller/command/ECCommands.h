#ifndef ECCOMMANDS_h
#define ECCOMMANDS_h

#include "ECCommand.h"
#include "ECDocument.h"

class InsertCommand : public Command	
{	
public:	
InsertCommand(Document& doc);
virtual void Execute(int x, int y, std::string str);

private:
Document& doc;
};

class New_LineCommand : public Command	
{	
public:	
New_LineCommand(Document& doc);
virtual void Execute(int x, int y);

private:
Document& doc;
};


#endif