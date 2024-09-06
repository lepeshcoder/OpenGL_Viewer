cmake_minimum_required(VERSION 3.28)
project(Project)

set(CMAKE_CXX_STANDARD 23)

find_package(assimp CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(nfd CONFIG REQUIRED)


add_executable(Project main.cpp
        main.cpp
        Entities/Vertex/Vertex.h
        Entities/Texture/Texture.h
        Enums/TextureType.h
        Mesh/Mesh.cpp
        Mesh/Mesh.h
        Entities/Material/Material.h
)

target_include_directories(Project PRIVATE ${Stb_INCLUDE_DIR})

target_link_libraries(Project PRIVATE
        assimp::assimp
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        nfd::nfd)



