#ifndef ECEDITORVIEW_h
#define ECEDITORVIEW_h


#include "ECTextViewImp.h"

class ECPage
{
public:
    std::vector<std::string> lines;
};

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
    void move_home();
    void move_end();
    void attach(ECObserver* ob);
    void show();
    void update_page(ECPage page);
    void set_x(int x);
    void set_y(int y);
    int page_size();
    int x;
    int y;
    int page_at(int y);
    void show_status_row(std::string message);
    void kill_status_row();
    void change_color(int y, int start, int end);
    void clear_color();
private:
    ECTextViewImp view;
    std::vector<ECPage> pages;
    int active_page;
    
};

#endif