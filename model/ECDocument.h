#ifndef ECDOCUMENT_h
#define ECDOCUMENT_h

#include <vector>
#include <string>
#include "ECCommand.h"
#include "ECTextViewImp.h"

class Document 
{
public:
    Document();
    void insert(int x, int y, const std::string& str);
    void new_line(int x, int y);
private:
    std::vector<std::string> lines;
};

#endif