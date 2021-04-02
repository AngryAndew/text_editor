#ifndef ECCONTROLLER_h
#define ECCONTROLLER_h

#include "ECEditorView.h"
#include "ECDocument.h"
class Controller 
{
public:
    Controller();
    void new_line();
    void quit();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    int get_key();
    void type(int key);
    void attach(ECObserver* ob);
    void show();
private:
    ECEditorView view;
    Document doc;
};
#endif