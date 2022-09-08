#include <iostream>

int main(){

    char* buffer = new char[10];
    
    for(int i = 0; i < 10; i++){
        buffer[i] = 0;
    }
    buffer[0] = 'a';
    printf("%s", buffer);
    delete[] buffer;
    return 0;
}