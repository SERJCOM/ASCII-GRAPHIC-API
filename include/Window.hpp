#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "WindowBuffer.hpp"

class Window {
public:
    int HEIGHT, WIDTH;

    std::string symbol = ".,-~:;=!*#$@";
    WindowBuffer screen;

    Window() {
        HEIGHT = 30;
        WIDTH = 120;
        screen.SetNewBuffer(HEIGHT * WIDTH + 1);
        offset = (float)(WIDTH / HEIGHT) * (11.0f / 24.0f);
        widthNormal = (float) 2 / WIDTH - 1 / WIDTH;
        heightNormal = (float) 2 / HEIGHT - 1 / HEIGHT;
        screen.buf[HEIGHT * WIDTH ]= '\n';
    }

    Window(int height, int width) : HEIGHT(height), WIDTH(width) {
        screen.SetNewBuffer(HEIGHT * WIDTH + 1);
        offset = (float)(WIDTH / HEIGHT) * (11.0f / 24.0f);
    }

    void SetPixel(glm::vec4 coor) {
        int x, y;
        x = (coor.x ) + WIDTH / 2;
        y = (coor.y ) + HEIGHT / 2;
        //x = x *  aspect * pixelaspect;
        if ( x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT) {
            int adress = static_cast<int>(x + y * WIDTH );
            screen.buf[adress] = symbol[2];
        }
    }

    void Draw() {
        printf( "%s", screen.buf);
    }

private:
    float offset; 
    float widthNormal, heightNormal;
    float aspect = (float)WIDTH / HEIGHT;
    float pixelaspect = 11.0f / 24.0f;
};