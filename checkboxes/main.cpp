#include "checkList.h"

int main(int argc, char const *argv[])
{
    int offset = 6;
    int index = 0;
    auto handle = GetStdHandle(STD_INPUT_HANDLE);

    std::cout << "\n    Pick your favorite colors by clicking mouse or space";
    
    std::string colour1[5] = {"Blue", "Red", "Orange", "Yellow", "Violet"};

    CheckList listOfBoxes(colour1);
    
    while (1)
    {
        INPUT_RECORD ir;
        DWORD count;

        ReadConsoleInput(handle, &ir, 1, &count);

        if (count)
        {
            if (ir.EventType == KEY_EVENT)
            {
                listOfBoxes.handleKeyboardEvent(ir.Event.KeyEvent);
            }
            if (ir.EventType == MOUSE_EVENT)
            {
                listOfBoxes.handleMouseEvent(ir.Event.MouseEvent);
            }
        }
    }
}