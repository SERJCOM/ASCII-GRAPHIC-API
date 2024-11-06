#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "WindowBuffer.hpp"
#include <string>

class Window {
public:
    int HEIGHT, WIDTH;

    std::string symbol = "`´¨·…¸ˆ˜’‚‘’:;›‹~“”„ª^—¡!|/)(+{*}?";
    WindowBuffer screen;

    Window() {
        HEIGHT = 38;
        WIDTH = 144;
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
        int x, y, z;
        x = (coor.x ) + WIDTH / 2;
        y = (coor.y *   aspect  ) + HEIGHT / 2;
        //y = y *  aspect * pixelaspect;
        if ( x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT) {
            int adress = static_cast<int>(x + y * WIDTH );
            
            if(coor.z < 0.0f){ coor.z = 0;}
            if (coor.z > 11.0f){ coor.z = 11.0f;}
            
            screen.buf[adress] = symbol[(int)coor.z];
        }
    }

    void Draw() {
        printf( "%s", screen.buf);
    }

private:
    float offset; 
    float widthNormal, heightNormal;
    float aspect = ((float)WIDTH / HEIGHT) * (11.0f / 24.0f);

};