#include <iostream>

#include <string>
#include "Window.hpp"
#include "Objects.hpp"
std::string logs;


int main()
{
    Window win;
    win.screen.ClearBuffer();

    Cube c(10);
    c.Draw(win);

    win.Draw();

    return 0;
}