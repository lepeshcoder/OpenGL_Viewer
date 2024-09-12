//
// Created by Lepesh on 11.09.2024.
//

#include "ModelStorage.h"

void ModelStorage::LoadModel(const string &modelFilePath) {
    if (ModelsByPath.contains(modelFilePath)) return;

    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(modelFilePath, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
        return;
    }

    std::vector<Mesh> meshes;
    for (uint32_t i = 0; i < scene->mNumMeshes; i++) {
        meshes.push_back(std::move(ProcessMesh(scene->mMeshes[i], scene)));
    }

    ModelsByPath[modelFilePath] = std::move(Model(meshes));
}


const Model &ModelStorage::GetModelByPath(const string &modelFilePath) {
    if (ModelsByPath.contains(modelFilePath))
        return ModelsByPath[modelFilePath];
    else std::cout << "model " << modelFilePath << "doesn't exist in modelStorage" << std::endl;
}

Mesh ModelStorage::ProcessMesh(aiMesh *mesh, const aiScene *scene) {
    std::vector<Vertex> vertexes;
    std::vector<uint32_t> indices;
    Material material{};

    // Vertexes
    for (uint32_t i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex{};
        if (mesh->HasPositions()) {
            vertex.Position.x = mesh->mVertices[i].x;
            vertex.Position.y = mesh->mVertices[i].y;
            vertex.Position.z = mesh->mVertices[i].z;
        }
        if (mesh->HasNormals()) {
            vertex.Normal.x = mesh->mNormals[i].x;
            vertex.Normal.y = mesh->mNormals[i].y;
            vertex.Normal.z = mesh->mNormals[i].z;
        }
        if (mesh->HasTextureCoords(0)) {
            vertex.TexCoords.s = mesh->mTextureCoords[0][i].x;
            vertex.TexCoords.t = mesh->mTextureCoords[0][i].y;
        }
        if (mesh->HasTangentsAndBitangents()) {
            vertex.Tangent.x = mesh->mTangents[i].x;
            vertex.Tangent.y = mesh->mTangents[i].y;
            vertex.Tangent.z = mesh->mTangents[i].z;
            vertex.Bitangent.x = mesh->mBitangents[i].x;
            vertex.Bitangent.y = mesh->mBitangents[i].y;
            vertex.Bitangent.z = mesh->mBitangents[i].z;
        }
        vertexes.push_back(vertex);
    }

    // Indices
    for (uint32_t i = 0; i < mesh->mNumFaces; i++) {
        for (uint32_t j = 0; j < mesh->mFaces[i].mNumIndices; j++) {
            indices.push_back(mesh->mFaces[i].mIndices[j]);
        }
    }

    // Materials
    aiMaterial *mat = scene->mMaterials[mesh->mMaterialIndex];
    material.AlbedoMapTextureId = LoadMaterialTextures(mat, aiTextureType_AMBIENT).Id;
    material.NormalMapTextureId = LoadMaterialTextures(mat, aiTextureType_NORMALS).Id;
    material.MetallicMapTextureId = LoadMaterialTextures(mat, aiTextureType_METALNESS).Id;
    material.RoughnessMapTextureId = LoadMaterialTextures(mat, aiTextureType_DIFFUSE_ROUGHNESS).Id;
    material.AmbientOcclusionMapTextureId = LoadMaterialTextures(mat, aiTextureType_AMBIENT_OCCLUSION).Id;

    return std::move(Mesh(vertexes, indices, material));
}

const Texture &ModelStorage::LoadMaterialTextures(aiMaterial *mat, aiTextureType type) {
    aiString str;
    mat->GetTexture(type, 0, &str);
    if (!TextureManager.IsTextureExist(str.C_Str())) {
        TextureType textureType;
        switch (type) {
            case aiTextureType_AMBIENT: {
                textureType = TextureType::ALBEDO_MAP;
                break;
            }
            case aiTextureType_NORMALS: {
                textureType = TextureType::NORMAL_MAP;
                break;
            }
            case aiTextureType_METALNESS: {
                textureType = TextureType::METALLIC_MAP;
                break;
            }
            case aiTextureType_DIFFUSE_ROUGHNESS: {
                textureType = TextureType::ROUGHNESS_MAP;
                break;
            }
            case aiTextureType_AMBIENT_OCCLUSION: {
                textureType = TextureType::AMBIENT_OCCLUSION_MAP;
                break;
            }
        }
        TextureManager.LoadTexture(str.C_Str(), textureType);
    }
    return TextureManager.GetTextureByPath(str.C_Str());
}


