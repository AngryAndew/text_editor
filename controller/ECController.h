#ifndef ECCONTROLLER_h
#define ECCONTROLLER_h

#include "ECEditorView.h"
#include "ECDocument.h"
class Controller 
{
public:
    Controller(std::string filename);
    void new_line();
    void quit();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void move_home();
    void move_end();
    int get_key();
    void type(int key);
    void del();
    void attach(ECObserver* ob);
    void show();
    void undo();
    void redo();
    bool vaild_cursor();
    void move_valid_cursor();
private:
    std::string filename;
    CommandHistory history;
    ECEditorView view;
    Document doc;
};
#endif