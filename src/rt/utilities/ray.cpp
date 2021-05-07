
#include <rt/utilities/ray.h>

namespace RT {

    Ray::Ray(const glm::vec3 &origin, const glm::vec3 &direction) : origin(origin),
                                                                    direction(glm::normalize(direction))
                                                                    {
    }

    Ray::~Ray() = default;

    glm::vec3 Ray::StepTo(float dt) const {
        return origin + dt * direction;
    }

}
