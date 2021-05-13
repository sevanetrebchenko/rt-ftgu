
#ifndef RT_HIT_RECORD_H
#define RT_HIT_RECORD_H

#include <pch.h>
#include <rt/materials/material.h>

namespace RT {

    struct HitRecord {
        HitRecord();
        ~HitRecord();

        float dt;
        glm::vec3 point;
        glm::vec3 normal;
        IMaterial* material;
    };

}

#endif //RT_HIT_RECORD_H
