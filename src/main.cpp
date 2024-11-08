#include <iostream>

#include <string>
// #include "Window.hpp"
// #include "Objects.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <array>

#include <unistd.h>

#include <thread>
#include <chrono>

int main()
{

    const int WIDTH = 156;
    const int HEIGHT = 40;

    std::array<char, WIDTH * HEIGHT + 1> data;

    data[WIDTH * HEIGHT ] = '\0';

    float bias = 16.0 / 9;

    char symbol[] = " .:o*$&#@";


    // char data_[HEIGHT];

    // for(int i = 0; i < HEIGHT; i++){
    //     data_[i] = std::to_string(i % 10).c_str()[0];
    //     // std::cout << i << std::endl;
    // }
    // printf("%s", data_);





    

    for (int i = 0; i < 10000; i++)
    {
        // std::cout << "\033[2J";
        // std::cout << "\033[H";

        for (int j = 0; j < HEIGHT; j++)
        {

            for (int i = 0; i < WIDTH; i++)
            {
                
                data[j * WIDTH + i] = ' ';

                float x = (i / (float)WIDTH) * 2 - 1;
                float y = (j / (float)HEIGHT) * 2 - 1;
                x = x * bias;

                if (x * x + y * y <= 0.5)
                {
                    float z = std::pow(std::abs(x * x + y * y - 0.5), 0.5);
                    int depth = (z) * 10;
                    data[j * WIDTH + i] = symbol[depth];
                }

                
            }
            // data[j * WIDTH + WIDTH ] = '\n';

            int index = j * WIDTH ;
            data[index] = std::to_string(j % 10).c_str()[0];
            // std::cout << index << std::endl;
        }
        data[WIDTH * HEIGHT - 1] = '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        printf("%s", data.data());
    }

    return 0;
}