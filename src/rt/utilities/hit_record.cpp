
#include <rt/utilities/hit_record.h>

namespace RT {

    HitRecord::HitRecord() : dt(-1),
                             point(glm::vec3(0.0f)),
                             normal(glm::vec3(0.0f)),
                             material(nullptr)
                             {
    }

    HitRecord::~HitRecord() = default;

}
