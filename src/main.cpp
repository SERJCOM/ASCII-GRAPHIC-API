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
    const int HEIGHT = 42;

    std::array<char, WIDTH * HEIGHT + 1> data;
    data[WIDTH * HEIGHT] = '\0';

    float bias = 16.0 / 9;

    char symbol[] = " .:o*$&#@";

    // std::cout <<"\u2582"<<std::endl;

    

    for (int i = 0; i < 10000; i++)
    {

        for (int i = 0; i < WIDTH; i++)
        {
            for (int j = 0; j < HEIGHT; j++)
            {

                float x = (i / (float)WIDTH) * 2 - 1;
                float y = (j / (float)HEIGHT) * 2 - 1;
                x = x * bias;

                if (x * x + y * y <= 0.5)
                {

                    float z = std::pow(std::abs(x * x + y * y - 0.5), 0.5);

                    int depth = (z) * 10;
                    // std::cout << z << '\n';

                    data[j * WIDTH + i] = symbol[depth];
                }
                else
                {
                    data[j * WIDTH + i] = ' ';
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
        printf("%s", data.data());
        // write(STDOUT_FILENO, data.data(), data.size());
    }

    return 0;
}