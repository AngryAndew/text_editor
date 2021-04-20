// Test code for editor
#include "ECTextViewImp.h"
#include <iostream>
#include "ECObservers.h"

using namespace  std;

int main(int argc, char *argv[])
{

    Controller editor =  Controller(argv[1]) ;

    Quit_Ob q_ob(editor);
    editor.attach(&q_ob);

    New_Line_Ob nl_ob(editor);
    editor.attach(&nl_ob);

    Typing_Ob t_ob(editor);
    editor.attach(&t_ob);

    Move_Left_Ob ml_ob(editor);
    editor.attach(&ml_ob);

    Move_Right_Ob mr_ob(editor);
    editor.attach(&mr_ob);

    Move_Up_Ob mp_ob(editor);
    editor.attach(&mp_ob);

    Move_Down_Ob md_ob(editor);
    editor.attach(&md_ob);

    Delete_Ob del_ob(editor);
    editor.attach(&del_ob);

    editor.show();
    
    return 0;
}
