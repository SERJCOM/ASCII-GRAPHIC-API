#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.hpp"

class Object{
    protected:
    glm::mat4 matrix = glm::mat4(1.0f);

    public:

    void Rotate(glm::vec3 axis, float angle){
        matrix = glm::rotate(matrix, glm::radians(angle), axis); 
    }

    void Scale(glm::vec3 scale){
        matrix = glm::scale(matrix, scale);
    }

    void Translate(glm::vec3 translate){
        matrix = glm::translate(matrix, translate);
    }
};

class Cube:public Object {
private:
    int WIDTH;
    glm::vec3 center = glm::vec3(0, 0, 0);


public:
    Cube(int width) : WIDTH(width) {}

    
    void Draw(Window &win) {
        for(float z = -1; z < 1 ; z+=(float)1/WIDTH){
            for (float i = -1; i < 1 ; i += (float)1 / WIDTH) {
                for (float j = -1; j < 1; j += (float) 1/ WIDTH) {
                    glm::vec4 point(i , j , z, 1.0f);
                    
                    point = point * matrix;
                    //std::cout << point.x << " " << point.y << " " << point.z << std::endl;
                    win.SetPixel(point);
                }
            }
        }
    }
};