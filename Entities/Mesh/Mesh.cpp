//
// Created by Lepesh on 06.09.2024.
//

#include "Mesh.h"

Mesh::Mesh(const vector<Vertex> &vertexes,
           const vector<uint32_t> &indices,
           const struct Material &material) {
    Vertexes = vertexes;
    Indices = indices;
    Material = material;
    VAO = VBO = EBO = 0;
    SetupMesh();
}

void Mesh::Draw(Shader& shader) {
    //TODO: Add Code with applying Textures
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES,Indices.size(),GL_UNSIGNED_INT,nullptr);
    glBindVertexArray(0);
}

const std::vector<Vertex> &Mesh::GetVertexes() {
    return Vertexes;
}

const std::vector<uint32_t> &Mesh::GetIndices() {
    return Indices;
}

const struct Material &Mesh::GetMaterial() {
    return Material;
}

void Mesh::SetupMesh() {
    glGenBuffers(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_VERTEX_ARRAY, VBO);
    glBufferData(GL_VERTEX_ARRAY, Vertexes.size() * sizeof(Vertex), Vertexes.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(uint32_t), Indices.data(), GL_STATIC_DRAW);

    //Position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, Position));
    // Normal
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, Normal));
    //TexCoords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, TexCoords));
    //Tangent
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, Tangent));
    //BiTangent
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, Bitangent));

    glBindVertexArray(0);
}
