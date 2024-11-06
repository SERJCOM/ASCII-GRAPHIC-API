#pragma once

#include <iostream>
#include <vector>


class WindowBuffer {

std::vector<char> color_buff;

public :

struct ViewPort{
    int x, y, width, height;
} viewport;


    void SetNewBuffer(int size)  {
        color_buff.reserve(size);
    }

    void ClearBuffer() {
        color_buff.clear();
    }

    std::vector<char>& GetData(){
        return color_buff;
    }

    void SetViewPort(int x, int y, int width, int height){
        viewport{x, y, width, height};
    }

};