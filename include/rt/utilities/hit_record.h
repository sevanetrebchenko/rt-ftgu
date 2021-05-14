
#ifndef RT_HIT_RECORD_H
#define RT_HIT_RECORD_H

#include <pch.h>

namespace RT {

    // Forward declaration.
    class IMaterial;

    struct HitRecord {
        HitRecord();
        ~HitRecord();

        float dt;
        glm::vec3 point;
        glm::vec3 normal;
        IMaterial* material;
    };

    struct ShadowHitRecord {
        ShadowHitRecord();
        ~ShadowHitRecord();

        float dt;
    };

}

#endif //RT_HIT_RECORD_H
