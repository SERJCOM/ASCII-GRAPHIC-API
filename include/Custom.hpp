#pragma once 

struct Coords{
    float x, y ,z;

    Coords(int x, int y){
        this->x = x;
        this->y = y;
        z = 1;
    }
};