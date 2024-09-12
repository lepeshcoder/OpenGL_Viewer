//
// Created by Lepesh on 11.09.2024.
//

#ifndef OPENGLPROJECT_MODELSTORAGE_H
#define OPENGLPROJECT_MODELSTORAGE_H

#include<iostream>
#include<unordered_map>
#include "../Entities/Model/Model.h"
#include "../Enums/TextureType.h"
#include "../TextureManager/TextureManager.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using std::vector,std::string,std::unordered_map;

class ModelStorage {

private:

    unordered_map<string,Model> ModelsByPath;

    TextureManager TextureManager;

    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);

    const Texture& LoadMaterialTextures(aiMaterial *mat, aiTextureType type);

public:

    // Main Methods
    void LoadModel(const string& modelFilePath);

    const Model& GetModelByPath(const string& modelFilePath);

};


#endif //OPENGLPROJECT_MODELSTORAGE_H
