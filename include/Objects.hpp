#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.hpp"

struct Cube {
    int WIDTH;
    glm::vec3 center = glm::vec3(0, 0, 0);
    glm::vec3 trans = glm::vec3(0, 0, 0);
    float angle;
    glm::mat4 matr = glm::mat4(1.0f);

    Cube(int width) : WIDTH(width) {}
    
    void RotateCube(float angl, glm::vec3 axis) {
        matr = glm::rotate(matr, angl, axis);
    }

    void Draw(Window &win) {
        for(float z = -1; z < 1 ; z+=(float)1/WIDTH){
            for (float i = -1; i < 1 ; i += (float)1 / WIDTH) {
                for (float j = -1; j < 1; j += (float) 1/ WIDTH) {
                    glm::vec4 point(i , j , z, 1.0f);
                    glm::mat4 model = glm::mat4(1.0f);
                    //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 
                    model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
                    point = point * model;
                    //std::cout << point.x << " " << point.y << " " << point.z << std::endl;
                    win.SetPixel(point);
                }
            }
        }
    }
};