#ifndef ECEDITORVIEW_h
#define ECEDITORVIEW_h


#include "ECTextViewImp.h"

class ECEditorView
{
public:
    ECEditorView();
    void refresh();
    void update(const std::vector<std::string>&  lines);
    void quit();
    int get_key();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void attach(ECObserver* ob);
    void show();
    int x;
    int y;
private:
    ECTextViewImp view;
    std::vector<std::string> lines;
    
};

#endif