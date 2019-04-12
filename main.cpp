#include "label.h"

int main(int argc, char** argv)
{
    Label l;
    l.setText("Hello more World");
    l.setPosition(11, 1);
    l.draw();

    Label g;
    g.setPosition(15,2);
    g.setText("Such label, so wow");
    g.draw();

    while(1);
}