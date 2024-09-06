//
// Created by Lepesh on 06.09.2024.
//

#ifndef OPENGLPROJECT_VERTEX_H
#define OPENGLPROJECT_VERTEX_H

#include<glm/glm.hpp>

/*
 * Vertex - structure that represent vertex of a 3D model,
 * designed to be a struct to use offsetof macro
 */

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
};

#endif //OPENGLPROJECT_VERTEX_H
