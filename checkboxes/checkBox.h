#include <iostream>
#include <string>
#include <windows.h>

class CheckBox
{
public:
    short width;
    short top;
    short left;
    int index;
    bool checked;
    bool hasBorder;
    WORD color;
    WORD background;
    std::string inputText;
    CheckBox(){};
    CheckBox(short width, short top, short left, std::string inputText, int index);
    void draw(std::string inputText, bool checked, int index);

    void handleKeyboardEvent(KEY_EVENT_RECORD &);
    void handleMouseEvent(MOUSE_EVENT_RECORD &);
};