#include "checkList.h"
#include <typeinfo>

CheckList::CheckList(std::string allStrings[])
{
    position = 1;
    offset = 3;
    index = 0;

    // for (int i = 0; i < 5; i++)
    // {
    //     Strings[i] = allStrings[i];
    //     std::cout << Strings[i] << std::endl;
    // }

    // CheckBox(5, offset * ++index, 1, allStrings[0], index);

    for (int i = 0; i < 5; i++)
    {
        allCheckBoxes[i] = CheckBox(0, offset * ++index, 1, allStrings[i], index);
    }
    draw(1);
}

CheckList::~CheckList()
{
    delete[] Strings;
}

void CheckList::handleKeyboardEvent(KEY_EVENT_RECORD &event)
{
    
    CONSOLE_SCREEN_BUFFER_INFO info;
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle, &info);
    auto offset = info.dwCursorPosition.X - this->left - 1;
    if (!event.bKeyDown)
        return;

    if (event.wVirtualKeyCode == VK_DOWN)
    {
        // std::cout << "down";
        if(position == 5)
            return;
        else{
            position++;
            draw(position);
        }
    }
    if (event.wVirtualKeyCode == VK_UP)
    {
        if(position == 1)
            return;
        else{
            position--;
            draw(position);
        } 
    }
    if (event.wVirtualKeyCode == VK_SPACE)
    {   
        allCheckBoxes[position-1].handleKeyboardEvent(event);
        draw(position);
    }
}

void CheckList::handleMouseEvent(MOUSE_EVENT_RECORD &event)
{
    if(event.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
    {
        if( event.dwMousePosition.X >=1 &&  event.dwMousePosition.X <= 4)
        {
            INPUT_RECORD ir;
            if(event.dwMousePosition.Y >= 3 &&  event.dwMousePosition.Y <= 17)
            {
                const int KEYEVENT_KEYUP = 0x02;
                keybd_event(VK_SPACE,0,0,0); 
                keybd_event(VK_SPACE,0,KEYEVENT_KEYUP,0);
                auto handle = GetStdHandle(STD_INPUT_HANDLE);
                // INPUT_RECORD ir;
                DWORD count;
                ReadConsoleInput(handle, &ir, 1, &count);
            }
            if(event.dwMousePosition.Y >= 3 &&  event.dwMousePosition.Y <= 5){
                allCheckBoxes[0].handleKeyboardEvent(ir.Event.KeyEvent);
                position = 1;
                draw(position);
            }
            if(event.dwMousePosition.Y >= 6 &&  event.dwMousePosition.Y <= 8){
               allCheckBoxes[1].handleKeyboardEvent(ir.Event.KeyEvent);
                position = 2;
                draw(position); 
            }
            if(event.dwMousePosition.Y >= 9 &&  event.dwMousePosition.Y <= 11){
                allCheckBoxes[2].handleKeyboardEvent(ir.Event.KeyEvent);
                position = 3;
                draw(position);
            }
            if(event.dwMousePosition.Y >= 12 &&  event.dwMousePosition.Y <= 14){
                allCheckBoxes[3].handleKeyboardEvent(ir.Event.KeyEvent);
                position = 4;
                draw(position);
            }
            if(event.dwMousePosition.Y >= 15 &&  event.dwMousePosition.Y <= 17){
                allCheckBoxes[4].handleKeyboardEvent(ir.Event.KeyEvent);
                position = 5;
                draw(position);
            }
        }
            // std::cout << event.dwMousePosition.Y << std::endl;

    }

    // CONSOLE_SCREEN_BUFFER_INFO info;
    // auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    // GetConsoleScreenBufferInfo(handle, &info);
    // auto offset = info.dwCursorPosition.X - this->left - 1;
}

void CheckList::draw(int index)
{
    COORD coord = {left, top};

    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(handle, coord);
    SetConsoleTextAttribute(handle, color | (background << 4));

    coord.X = 3;
    if(index == 1)
        coord.Y = 4;
    else
    {
       coord.Y = index * 3 + 1;
    }
    
    SetConsoleCursorPosition(handle, {coord.X, coord.Y});

}