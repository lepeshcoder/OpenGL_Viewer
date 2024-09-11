//
// Created by Lepesh on 11.09.2024.
//

#ifndef OPENGLPROJECT_SHADER_H
#define OPENGLPROJECT_SHADER_H


#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>

using std::string;

class Shader {
public:
    unsigned int ID;

    Shader(const string& vertexPath, const string& fragmentPath);

    void use() const;

    void setUniform(const string& name, bool value) const;

    void setUniform(const string& name, int value) const;

    void setUniform(const string& name, float value) const;

    void setUniform(const std::string &name, const glm::mat4 &mat) const;



private:
    static void checkCompileErrors(unsigned int shader, const string& type);

};



#endif //OPENGLPROJECT_SHADER_H
