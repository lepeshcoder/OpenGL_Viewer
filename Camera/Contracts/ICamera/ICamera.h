//
// Created by Lepesh on 12.09.2024.
//

#ifndef OPENGLPROJECT_ICAMERA_H
#define OPENGLPROJECT_ICAMERA_H

#include <glm/glm.hpp>

class ICamera {

public:

    virtual const glm::mat4& GetViewMatrix();


};


#endif //OPENGLPROJECT_ICAMERA_H
