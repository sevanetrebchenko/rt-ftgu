
#include <rt/utilities/hit_record.h>

namespace RT {

    HitRecord::HitRecord() : hit(false),
                             dt(-1),
                             point(glm::vec3(0.0f)),
                             normal(glm::vec3(0.0f)),
                             color(glm::vec3(0.0f))
                             {
    }

    HitRecord::~HitRecord() = default;

}
