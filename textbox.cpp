#include "textbox.h"
#include <iostream>
#include <algorithm>

TextBox::TextBox(short width, short top, short left, std::string value) : 
    width(width), top(top), value(value), left(left), hasBorder(true),
    color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY),
    background(0)  { }

void TextBox::handleKeyboardEvent(KEY_EVENT_RECORD& event)
{
    if (!event.bKeyDown) return;

    if (event.wVirtualKeyCode >= 0x30 && event.wVirtualKeyCode <= 0x5a)
    {
        value.push_back(event.uChar.AsciiChar);
        draw();
    }

    if (event.wVirtualKeyCode == VK_LEFT || event.wVirtualKeyCode == VK_RIGHT)
    {
        int textWidth = value.length();
        CONSOLE_SCREEN_BUFFER_INFO info;

        auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(handle, &info);
        
        auto offset = info.dwCursorPosition.X - this->left - 1; // absolute cursor position in textbox 

        if (offset > 0 && event.wVirtualKeyCode == VK_LEFT)
        {
            SetConsoleCursorPosition(handle,{ info.dwCursorPosition.X - 1, info.dwCursorPosition.Y });
        }

        if (offset > textWidth && event.wVirtualKeyCode == VK_RIGHT)
        {
            SetConsoleCursorPosition(handle,{ info.dwCursorPosition.X + 1, info.dwCursorPosition.Y });
        }
    }

    if (event.wVirtualKeyCode == VK_BACK)
    {
        value.pop_back();
        draw();
    }

    // switch(event.wVirtualKeyCode)
    // {

    // }
}

void TextBox::draw()
{
    COORD coord = { left, top };
    
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleCursorPosition(handle, coord);
    SetConsoleTextAttribute(handle, color | (background << 4));
    
    std::cout << (char) 0xda; // left top corner
    for (int i=0; i<width; i++) //top line
        std::cout << (char) 0xc4;
    std::cout << (char) 0xbf; //right top corner

    SetConsoleCursorPosition(handle, {coord.X, coord.Y+1});
    std::cout << (char) 0xb3; //vertical line
    
    for (int i =0; i < width; i++)
        std::cout << (i >= value.length() ? ' ' : value[i]);
    
    SetConsoleCursorPosition(handle, { left + width + 1, top + 1 });
    std::cout << (char) 0xb3; //vertical line

    SetConsoleCursorPosition(handle, { left, top + 2 });
    std::cout << (char) 0xc0; // bottom left corner
    for (int i = 0; i < width; i++) // bottom border
        std::cout << (char) 0xc4;
    std::cout << (char) 0xd9; //right bottom corner

    SetConsoleCursorPosition(handle, { left + 1 + value.length(), top+1 });

}

