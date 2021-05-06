
#ifndef RT_HIT_RECORD_H
#define RT_HIT_RECORD_H

#include <pch.h>

namespace RT {

    struct HitRecord {
        HitRecord();
        ~HitRecord();

        bool hit;
        float dt;
        glm::vec3 point;
        glm::vec3 normal;
        glm::vec3 color;
    };

}

#endif //RT_HIT_RECORD_H
