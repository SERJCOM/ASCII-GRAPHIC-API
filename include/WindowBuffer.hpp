#pragma once

#include <iostream>
#include "Buffer.hpp"

class WindowBuffer: public Buffer{
    public:
        virtual void ClearBuffer(){
            for (int i = 0; i < size; i++) {
                buf[i] = ' ';
            }
            buf[size - 1] = '\n';
        }

};