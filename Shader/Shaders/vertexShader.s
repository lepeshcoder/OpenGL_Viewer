#version 330 core

in vec3 aPos;
in vec3 aNorm;
in vec2 aTex;
in vec3 aTang;
in vec3 aBiTang;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}