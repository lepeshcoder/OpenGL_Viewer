//
// Created by Lepesh on 11.09.2024.
//

#include "TextureManager.h"

void TextureManager::LoadTexture(const string& textureFilePath, TextureType type) {
    if(TexturesByPath.contains(textureFilePath)) return;
    uint32_t textureId = TextureFromFile(textureFilePath);
    TexturesByPath[textureFilePath] = std::move(Texture(textureId,type,textureFilePath));
}

const Texture &TextureManager::GetTextureByPath(const string &textureFilePath) {
    if(TexturesByPath.contains(textureFilePath)) return TexturesByPath[textureFilePath];
    else std::cout << "texture " << textureFilePath << "doesn't exist in textureManager" << std::endl;
}

uint32_t TextureManager::TextureFromFile(const string &textureFilePath) {

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(textureFilePath.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << textureFilePath << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

bool TextureManager::IsTextureExist(const string &textureFilePath) {
    return TexturesByPath.contains(textureFilePath);
}

