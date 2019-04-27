#include "checkBox.h"
#include <iostream>
#include <algorithm>

CheckBox::CheckBox(short width, short top, short left, std::string inputText, int index) : width(width), top(top), inputText(inputText), left(left), index(index), checked(false), hasBorder(true),
                                                                                           color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY),
                                                                                           background(0)
{
    draw(inputText, checked, index);
}

void CheckBox::handleKeyboardEvent(KEY_EVENT_RECORD &event)
{

    CONSOLE_SCREEN_BUFFER_INFO info;
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle, &info);
    auto offset = info.dwCursorPosition.X - this->left - 1;
    if (!event.bKeyDown)
        return;

    if (event.wVirtualKeyCode == 0x20)
    {
        checked = !checked;
        draw(inputText, checked, index);
    }
}

void CheckBox::handleMouseEvent(MOUSE_EVENT_RECORD &event)
{

    CONSOLE_SCREEN_BUFFER_INFO info;
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle, &info);
    auto offset = info.dwCursorPosition.X - this->left - 1;
}





void CheckBox::draw(std::string inputText, bool checked, int index)
{
    COORD coord = coord = {left, top};

    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(handle, coord);
    SetConsoleTextAttribute(handle, color | (background << 4));

    std::cout << (char)0xda; // left top corner
    std::cout << (char)0xc4; //horizontal line
    std::cout << (char)0xc4; //horizontal line
    std::cout << (char)0xc4; //horizontal line
    std::cout << (char)0xbf; //right top corner
    SetConsoleCursorPosition(handle, {coord.X, coord.Y + 1});
    std::cout << (char)0xb3; //vertical line
    std::cout << ' ';        //

    if (checked)
        std::cout << (char)0xFE;
    else
        std::cout << ' '; //cube

    std::cout << ' ';        //
    std::cout << (char)0xb3; //vertical lines
    SetConsoleCursorPosition(handle, {coord.X, coord.Y + 2});
    std::cout << (char)0xc0; // bottom left corner
    std::cout << (char)0xc4; //horizontal line
    std::cout << (char)0xc4; //horizontal line
    std::cout << (char)0xc4; //horizontal line
    std::cout << (char)0xd9; //right bottom corner

    SetConsoleCursorPosition(handle, {coord.X + 6, coord.Y + 1});
    std::cout << inputText;

    SetConsoleCursorPosition(handle, {coord.X + 2, index * coord.Y + 1});

    // SetConsoleCursorPosition(handle, {coord.X - 1, coord.Y});
    // std::cout << (char)0xFE; //cube
    // SetConsoleCursorPosition(handle, {coord.X - 1, coord.Y});
    // std::cout << (char)0xb3; //vertical line
    // SetConsoleCursorPosition(handle, {coord.X, coord.Y + 1});
    // std::cout << (char)0xc0; // bottom left corner
    // std::cout << (char)0xc4; //horizontal line
    // std::cout << (char)0xd9; //right bottom corner

    // std::cout << (char)0xb3; //vertical line

    // std::cout << (i >= value.length() ? ' ' : value[i]);
    // std::cout << ' ';
    // SetConsoleCursorPosition(handle, {left + 3, top + 1});
    // // std::cout << (char)0xb3; //vertical line

    // SetConsoleCursorPosition(handle, {left, top + 2});
    // std::cout << (char)0xc0; // bottom left corner
    // std::cout << (char)0xc4; // bottom border
    // std::cout << (char)0xc4; // bottom border
    // std::cout << (char)0xd9; //right bottom corner

    // if (X != -1)
    //     SetConsoleCursorPosition(handle, {left + 1 + X, top + 1});
    // else
    //     SetConsoleCursorPosition(handle, {left + 1 + value.length(), top + 1});
}
