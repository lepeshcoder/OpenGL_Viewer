//
// Created by Lepesh on 12.09.2024.
//

#include "Scene.h"

Scene::Scene(CameraType cameraType) {
    switch(cameraType)
    {
        case CameraType::ArcBallCamera:{
            camera = new ArcBallCamera();
            break;
        }
        case CameraType::FPSCamera:{
            camera = new FPSCamera();
            break;
        }
    }

}

Scene::~Scene() {
    delete camera;
}

void Scene::AddModel(const string &name, const Model &model) {
    if(ModelsByName.contains(name)) return;
    ModelsByName[name] = model;
}

void Scene::RemoveModel(const string &name) {
    if(ModelsByName.contains(name)) return;
    ModelsByName.erase(name);
}

const Model &Scene::GetModelByName(const string &name) {
    return ModelsByName[name];
}
