//
// Created by Lepesh on 11.09.2024.
//

#include "Model.h"

Model::Model(const vector<Mesh> &meshes, const glm::mat4 &modelMatrix) {
    Meshes = meshes;
    ModelMatrix = modelMatrix;
}

void Model::Draw(Shader &shader) {
    //TODO: add uniforms as modelMatrix and etc to shader
    for( Mesh& mesh : Meshes){
        mesh.Draw(shader);
    }
}

const vector<Mesh> &Model::GetMeshes() {
    return Meshes;
}

const glm::mat4 &Model::GetModelMatrix() {
    return ModelMatrix;
}
