#pragma once

#include "WindowBuffer.hpp"
#include "Custom.hpp"
#include <vector>

class Shader{

std::vector<Coords> data; 

WindowBuffer& buff;

public:

    Shader() = default;


    void SetBuffer(WindowBuffer& buff){
        this->buff = buff;
    }

    void Compute(){
        
    }



    void SetData(std::vector<Coords>& coords){
        for(Coords coord : coords){
            
        }
    }



};