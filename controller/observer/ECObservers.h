#ifndef ECOBERVERS_H
#define ECOBERVERS_H

#include "ECController.h"

class Quit_Ob : public ECObserver
{
public:
    Quit_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class New_Line_Ob : public ECObserver
{
public:
    New_Line_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Move_Left_Ob : public ECObserver
{
public:
    Move_Left_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Move_Right_Ob : public ECObserver
{
public:
    Move_Right_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Move_Up_Ob : public ECObserver
{
public:
    Move_Up_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Move_Down_Ob : public ECObserver
{
public:
    Move_Down_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Typing_Ob : public ECObserver
{
public:
    Typing_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Delete_Ob : public ECObserver
{
public:
    Delete_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Undo_Ob : public ECObserver
{
public:
    Undo_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Redo_Ob : public ECObserver
{
public:
    Redo_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Search_Ob : public ECObserver
{
public:
    Search_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Quit_Search_Ob : public ECObserver
{
public:
    Quit_Search_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

class Replace_Ob : public ECObserver
{
public:
    Replace_Ob(Controller& control);
    void Update();
private:
    Controller& control;
};

#endif