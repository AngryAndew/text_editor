#ifndef ECEDITORVIEW_h
#define ECEDITORVIEW_h


#include "ECTextViewImp.h"

class ECEditorView
{
public:
ECEditorView(ECTextViewImp& view);
void refresh();
void update();
void quit();
int get_key();
void move_left();
void move_right();
void move_up();
void move_down();
private:
ECTextViewImp& view;
std::vector<std::string> lines;
int x = view.GetCursorX();
int y = view.GetCursorY();
};

#endif