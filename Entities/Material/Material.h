//
// Created by Lepesh on 06.09.2024.
//

#ifndef OPENGLPROJECT_MATERIAL_H
#define OPENGLPROJECT_MATERIAL_H

#include<iostream>
#include<vector>

struct Material{
    uint32_t AlbedoMapTextureId;
    uint32_t NormalMapTextureId;
    uint32_t MetallicMapTextureId;
    uint32_t RoughnessMapTextureId;
    uint32_t AmbientOcclusionMapTextureId;
};


#endif //OPENGLPROJECT_MATERIAL_H
