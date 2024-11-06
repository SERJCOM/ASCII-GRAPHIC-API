#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include "Window.hpp"
#include "Custom.hpp"
#include "Shader.hpp"



class IObject{
    protected:
    glm::mat4 matrix = glm::mat4(1.0f);
    glm::mat4 addMat;

    std::vector<Coords> coords;

    public:

    // virtual void Draw()

    void Rotate(glm::vec3 axis, float angle){
        matrix = glm::rotate(matrix, glm::radians(angle), axis); 
    }

    void Scale(glm::vec3 scale){
        matrix = glm::scale(matrix, scale);
    }

    void Translate(glm::vec3 translate){
        matrix = glm::translate(matrix, translate);
    }

    void AddMatrix(glm::mat4 mat){
        addMat = mat;
    }
};

class Cube:public IObject {
private:

    int WIDTH = 10;
    int HEIGHT = 10;

public:
    Cube(){
        coords.clear();
        for(int x = 0; x < WIDTH; x++){
            for(int y = 0; y < HEIGHT; y++){
                if(std::abs(x+y) + std::abs(x-y) <= WIDTH){
                    coords.push_back(Coords(x, y));
                }
            }
        }
    }

    
    void Draw(Shader& shader) {
        shader.SetData(coords);
    }
};