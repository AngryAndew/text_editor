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
    char del(int x, int y);
    int join_line(int x, int y);
    int line_size(int y);
    void save_file(std::string filename);
    void load_file(std::string filename);
    int total_lines();
    std::vector<std::vector<int>> find_string(std::string str);
    void replace(int x, int y, std::string status, std::string text);
private:
    ECEditorView& view;
    std::vector<std::string> lines;
    void update();
};

#endif