#ifndef ECDOCUMENT_h
#define ECDOCUMENT_h

#include <vector>
#include <string>
#include "ECCommand.h"
#include "ECTextViewImp.h"
#include "ECEditorView.h"
class Document 
{
public:
    Document(ECEditorView& view);
    void insert(int x, int y, const std::string& str);
    void new_line(int x, int y);
private:
    ECEditorView& view;
    std::vector<std::string> lines;
    void update();
};

#endif