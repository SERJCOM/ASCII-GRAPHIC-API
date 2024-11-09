#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <array>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <algorithm>

class Sphere
{

    std::vector<glm::vec3> coords;

    int render_size;

    int radius;

public:
    Sphere(int render_size, int radius)
    {
        this->render_size = render_size;
        this->radius = radius;
    }

    void Render()
    {
        for (int j = 0; j < render_size; j++)
        {
            for (int i = 0; i < render_size; i++)
            {
                glm::vec2 screen_coord = glm::vec2((i / (float)render_size) * 2 - 1, (j / (float)render_size) * 2 - 1);

                if (std::pow(screen_coord.x, 2) + std::pow(screen_coord.y, 2) <= (float)radius / render_size)
                {
                    float z = std::pow(std::abs(std::pow(screen_coord.x, 2) + std::pow(screen_coord.y, 2) - (float)radius / render_size), 0.5);

                    coords.push_back(glm::vec3(screen_coord.x, screen_coord.y, z));

                }
            }
        }
    }

    const std::vector<glm::vec3> &GetCoords() const 
    {
        return coords;
    }
};

template <typename T>
bool CheckNotStrictRange(T val, T lo, T hi)
{
    if (val >= lo && val <= hi)
        return true;
    return false;
}

template <typename T>
bool CheckStrictRange(T val, T lo, T hi)
{
    if (val > lo && val < hi)
        return true;
    return false;
}

glm::vec2 NormalUVtoAbsUV(glm::vec2 nUV, int width, int height)
{
    glm::vec2 ret;

    ret.x = (int)((nUV.x + 1) / 2 * (float)width);
    ret.y = (int)((nUV.y + 1) / 2 * (float)height);

    return ret;
}

int main()
{

    const int WIDTH = 211;
    const int HEIGHT = 49;

    std::array<char, WIDTH * HEIGHT + 1> data;

    float bias = 16.0 / 9;

    char symbol[] = " .:!/r(l1Z4H9W8$@";

    int depth_size = sizeof(symbol);

    glm::vec2 uv;
    glm::vec3 camera_coord = glm::vec3(0, 0, -1);

    Sphere sphere(50, 25);
    sphere.Render();

    for (int t = 0; t < 10000; t++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            for (int i = 0; i < WIDTH; i++)
            {
                data[j * WIDTH + i] = ' ';
            }
        }

        for (const auto vec_ : sphere.GetCoords())
        {
            glm::vec3 vec = vec_;
            // vec *= 10;

            vec.y *= bias;

            vec *= 0.5;

            vec += glm::vec3(glm::vec2(sin(t * 0.1)), 0.0f);

            

            // uv = glm::vec2((vec.x / (float)WIDTH) * 2 - 1, (vec.y / (float)HEIGHT) * 2 - 1);

            uv = vec;

            if (CheckNotStrictRange(uv.x, -1.0f, 1.0f) && CheckNotStrictRange(uv.y, -1.0f, 1.0f))
            {
                uv.x = std::clamp(uv.x, -1.0f, 1.0f);
                uv.y = std::clamp(uv.y, -1.0f, 1.0f);
                float depth = std::clamp(vec.z * 5, 0.0f, (float)depth_size - 2);

                glm::vec2 absUv = NormalUVtoAbsUV(uv , WIDTH, HEIGHT);
                data[absUv.y * WIDTH + absUv.x] = symbol[(int)depth];
            }
        }

        data[WIDTH * HEIGHT] = '\n';

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        printf(data.data());
    }

    return 0;
}
