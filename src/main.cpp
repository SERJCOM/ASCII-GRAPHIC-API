#include <iostream>

#include <string>
#include "Window.hpp"
#include "Objects.hpp"
std::string logs;


int main()
{
    Window win;
    
    Cube c(10);
    c.Scale(glm::vec3(10.0f, 10.0f, 10.0f));
    for(int i = 0; i < 10000; i++){
        
        win.screen.ClearBuffer();   
        
        c.Rotate(glm::vec3(1.0f, 1.0f, 0.0f), sin(i) * 10);
        c.Draw(win);

        win.Draw();
    }

    return 0;
}