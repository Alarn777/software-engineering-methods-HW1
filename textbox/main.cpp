#include "label.h"
#include "textbox.h"

int main(int argc, char const *argv[])
{
    auto handle = GetStdHandle(STD_INPUT_HANDLE);

    TextBox tb(12, 3, 3, "12345");
    tb.draw(-1);
    
    while (1)
    {
        INPUT_RECORD ir;
        DWORD count;

        ReadConsoleInput(handle, &ir, 1, &count);

        if (count)
        {
            if (ir.EventType == KEY_EVENT)
            {
                tb.handleKeyboardEvent(ir.Event.KeyEvent);
            }
        }
    }
}