
#include <rt/utilities/hit_record.h>

namespace RT {

    HitRecord::HitRecord() : dt(-1.0f),
                             point(glm::vec3(0.0f)),
                             normal(glm::vec3(0.0f)),
                             material(nullptr)
                             {
    }

    HitRecord::~HitRecord() = default;



    ShadowHitRecord::ShadowHitRecord() : dt(-1.0f) {
    }

    ShadowHitRecord::~ShadowHitRecord() = default;

}
