#include <iostream>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include "Buffer.hpp"

std::string logs;



class Window {
public:
    int HEIGHT, WIDTH;

    std::string symbol = ".,-~:;=!*#$@";
    Buffer screen;

    Window() {
        HEIGHT = 30;
        WIDTH = 120;
        screen.SetNewBuffer(HEIGHT * WIDTH + 1);
        offset = (float)(WIDTH / HEIGHT) * (11.0f / 24.0f);
        widthNormal = (float) 2 / WIDTH - 1 / WIDTH;
        heightNormal = (float) 2 / HEIGHT - 1 / HEIGHT;
    }

    Window(int height, int width) : HEIGHT(height), WIDTH(width) {
        screen.SetNewBuffer(HEIGHT * WIDTH + 1);
        offset = (float)(WIDTH / HEIGHT) * (11.0f / 24.0f);
    }

    void SetPixel(glm::vec4 coor) {
        float x, y, z;
        x = 2 * coor.x / 120 - 1;
        if (coor.z > 0 && coor.x >= 0 && coor.y >= 0 && coor.x < WIDTH && coor.y < HEIGHT) {
            
            screen.buf[static_cast<int>(x + coor.y * WIDTH)] = symbol[2];
        }
        else {
            screen.buf[static_cast<int>(x + coor.y * WIDTH)] = ' ';
        }
    }

    void Draw() {
        printf(screen.buf);
    }

private:
    float offset; 
    float widthNormal, heightNormal;
};

struct Cube {
    int WIDTH;
    glm::vec3 center = glm::vec3(0, 0, 0);
    glm::vec3 trans = glm::vec3(0, 0, 0);
    float angle;
    glm::mat4 matr = glm::mat4(1.0f);

    Cube(int width) : WIDTH(width) {}
    
    void RotateCube(float angl, glm::vec3 axis) {
        matr = glm::rotate(matr, angl, axis);
    }

    void Draw(Window &win) {
        for (float i = -1; i < 1; i += (float)1 / WIDTH) {
            for (float j = -1; j < 1; j += (float) 1 / WIDTH) {
                
            }
        }
    }
};

int main()
{
    Window win;
    win.screen.ClearBuffer();

    Cube c(10);
    //c.RotateCube(10, glm::vec3(0, 1.0f, 0));
    c.Draw(win);

    win.Draw();

    //std::cout << "\n" << logs.c_str() << std::endl;
    return 0;
}