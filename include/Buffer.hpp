#pragma once

#include <iostream>


class Buffer {
public:
    char* buf = nullptr;
    int size;


    void SetNewBuffer(int size);

    virtual void ClearBuffer();

    ~Buffer(){
        delete[] buf;
    }


};