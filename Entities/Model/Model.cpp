//
// Created by Lepesh on 11.09.2024.
//

#include "Model.h"

Model::Model(const vector<Mesh> &meshes, enum Pipeline pipeline, const glm::mat4 &modelMatrix) {
    Meshes = meshes;
    Pipeline = pipeline;
    ModelMatrix = modelMatrix;
}

void Model::Draw(Shader &shader) const {
    //TODO: add uniforms as modelMatrix and etc to shader
    for(const auto & mesh : Meshes){
        mesh.Draw(shader);
    }
}

const vector<Mesh> &Model::GetMeshes() {
    return Meshes;
}

const glm::mat4 &Model::GetModelMatrix() {
    return ModelMatrix;
}




