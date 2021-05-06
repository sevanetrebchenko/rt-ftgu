
#ifndef RT_RAY_H
#define RT_RAY_H

#include <pch.h>

namespace RT {

    struct Ray {
        explicit Ray(const glm::vec3& origin = glm::vec3(0.0f), const glm::vec3& direction = glm::vec3(0.0f, 0.0f, 1.0f));
        ~Ray();

        [[nodiscard]] glm::vec3 StepTo(float dt) const;

        glm::vec3 origin;
        glm::vec3 direction;
    };

}

#endif //RT_RAY_H
