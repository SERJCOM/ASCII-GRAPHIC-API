#include "Buffer.hpp"


void Buffer::SetNewBuffer(int size) {
        delete[] buf;
        buf = new char[size];
        this->size = size;
    }

void Buffer::ClearBuffer() {
    for (int i = 0; i < size; i++) {
        buf[i] = 0;
    }
    buf[size - 1] = '\n';
}

