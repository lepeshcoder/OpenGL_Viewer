//
// Created by Lepesh on 06.09.2024.
//

#ifndef OPENGLPROJECT_MESH_H
#define OPENGLPROJECT_MESH_H

#include<iostream>
#include<vector>
#include "../Entities/Vertex/Vertex.h"
#include "../Entities/Material/Material.h"

using std::vector, std::string;

class Mesh {

private:

    std::vector<Vertex> Vertexes;
    std::vector<uint32_t> Indices;
    Material Material;

public:



};


#endif //OPENGLPROJECT_MESH_H
