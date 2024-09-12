//
// Created by Lepesh on 11.09.2024.
//

#ifndef OPENGLPROJECT_MODEL_H
#define OPENGLPROJECT_MODEL_H

#include<vector>
#include "../Mesh/Mesh.h"

using std::vector, std::string;

class Model {

private:

    // Model's meshes
    vector<Mesh> Meshes;
    // Model matrix
    glm::mat4 ModelMatrix{};

public:

    Model() = default;

    Model(const vector<Mesh>& meshes, const glm::mat4& modelMatrix = glm::mat4(0));

    // Main Methods

    void Draw(Shader& shader) const;

    // Getters

    const vector<Mesh>& GetMeshes();

    const glm::mat4& GetModelMatrix();

};


#endif //OPENGLPROJECT_MODEL_H
