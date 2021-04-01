#ifndef ECCONTROLLER_h
#define ECCONTROLLER_h

#include "ECEditorView.h"
#include "ECDocument.h"
class Controller 
{
public:
    Controller(ECEditorView view, Document doc);
    void insert();
    void new_line();
    void quit();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    int get_key();
private:
    ECEditorView view;
    Document doc;
};
#endif