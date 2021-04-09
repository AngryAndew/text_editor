#ifndef ECCOMMANDS_h
#define ECCOMMANDS_h

#include "ECCommand.h"
#include "ECDocument.h"

class InsertCommand : public Command	
{	
public:	
    InsertCommand(Document& doc, int x, int y, std::string str);
    virtual void Execute();
private:
    Document& doc;
    int x;
    int y;
    std::string str;
};

class New_LineCommand : public Command	
{	
public:	
    New_LineCommand(Document& doc, int x, int y);
    virtual void Execute();
private:
    Document& doc;
    int x;
    int y;
};

class DeleteCommand : public Command	
{	
public:	
    DeleteCommand(Document& doc, int x, int y);
    virtual void Execute();
private:
    Document& doc;
    int x;
    int y;
};

class Join_LineCommand : public Command	
{	
public:	
    Join_LineCommand(Document& doc, int x, int y);
    virtual void Execute();
private:
    Document& doc;
    int x;
    int y;
};


#endif