//
// Created by Lepesh on 06.09.2024.
//

#ifndef OPENGLPROJECT_MESH_H
#define OPENGLPROJECT_MESH_H

#include<iostream>
#include<vector>
#include<glad/glad.h>
#include "../Vertex/Vertex.h"
#include "../Material/Material.h"
#include "../../Shader/Shader.h"

using std::vector, std::string;

class Mesh {

private:

    std::vector<Vertex> Vertexes;
    std::vector<uint32_t> Indices;
    Material Material{};

    //OpenGL buffers for drawing mesh
    uint32_t VAO,VBO,EBO;

    void SetupMesh();

public:

    //TODO: IMPLEMENT MESH METHODS!!!

    Mesh() = default;

    Mesh(const std::vector<Vertex>& vertexes,
         const std::vector<uint32_t >& indices,
         const struct Material& material);

    // Main Methods

    void Draw(Shader& shader) const;




    //Getters (returns const reference)
    const std::vector<Vertex>& GetVertexes();

    const std::vector<uint32_t>& GetIndices();

    const struct Material& GetMaterial();

};


#endif //OPENGLPROJECT_MESH_H
