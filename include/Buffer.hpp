#pragma once

#include <iostream>


class Buffer {
public:
    char* buf = nullptr;
    int size;


    void SetNewBuffer(int size);

    void ClearBuffer();

    ~Buffer(){
        delete[] buf;
    }


};