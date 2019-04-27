#include <iostream>
#include <string>
#include <windows.h>
#include "checkBox.h"

class CheckList
{
public:
    short width;
    short top;
    short left;
    int index;
    int offset;
    int position;
    CheckBox allCheckBoxes[5];
    WORD color;
    WORD background;
    std::string Strings[5];
    CheckList(std::string allStrings[5]);
    void draw(int index);
    void handleKeyboardEvent(KEY_EVENT_RECORD &);
    void handleMouseEvent(MOUSE_EVENT_RECORD &);
    ~CheckList();
};