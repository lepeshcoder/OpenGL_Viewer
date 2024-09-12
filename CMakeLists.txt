cmake_minimum_required(VERSION 3.28)
project(Project)

set(CMAKE_CXX_STANDARD 23)



add_executable(Project
        main.cpp
        Entities/Vertex/Vertex.h
        Entities/Texture/Texture.h
        Enums/TextureType.h
        Entities/Mesh/Mesh.cpp
        Entities/Mesh/Mesh.h
        Entities/Material/Material.h
        Shader/Shader.cpp
        Shader/Shader.h
        Entities/Model/Model.cpp
        Entities/Model/Model.h
        Enums/PipelineType.h
        ModelStorage/ModelStorage.cpp
        ModelStorage/ModelStorage.h
        TextureManager/TextureManager.cpp
        TextureManager/TextureManager.h
        stb_Image.cpp
        Camera/Contracts/ICamera/ICamera.h
)


find_package(assimp CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(nfd CONFIG REQUIRED)

target_include_directories(Project PRIVATE ${Stb_INCLUDE_DIR})

target_link_libraries(Project PRIVATE
        assimp::assimp
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        nfd::nfd)



