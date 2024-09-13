//
// Created by Lepesh on 12.09.2024.
//

#ifndef OPENGLPROJECT_SCENE_H
#define OPENGLPROJECT_SCENE_H

#include<iostream>
#include<unordered_map>
#include "../Entities/Model/Model.h"
#include "../Camera/Contracts/ICamera/ICamera.h"
#include "../Enums/CameraType.h"
#include "../Camera/Implementations/ArcBallCamera/ArcBallCamera.h"
#include "../Camera/Implementations/FPSCamera/FPSCamera.h"
#include "../ModelStorage/ModelStorage.h"
#include "../Light/Implementations/DirectionalLight/DirectionalLight.h"
#include "../Light/Implementations/PointLight/PointLight.h"
#include "../Light/Implementations/SpotLight/SpotLight.h"

using std::unordered_map, std::string;

class Scene {

private:

    // name is primary key for models and Lights on the scene
    unordered_map<string, Model> ModelsByName;

    unordered_map<string, ILight*> Lights;

    //camera
    ICamera* camera;

    ModelStorage modelStorage;

  //  Drawer drawer;

public:

    explicit Scene(CameraType cameraType);

    void AddModel(const string& name, const Model& model);

    void RemoveModel(const string& name);

    void AddLight(const string& name, ILight* light);

    void RemoveLight(const string& name);

    const Model& GetModelByName(const string& name);

    ~Scene();

};


#endif //OPENGLPROJECT_SCENE_H
