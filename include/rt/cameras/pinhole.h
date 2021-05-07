
#ifndef RT_PINHOLE_H
#define RT_PINHOLE_H

#include <rt/cameras/camera.h>

namespace RT {

    class Pinhole : public ICamera {
        public:
            Pinhole(const glm::vec3& position, const glm::vec3& lookat, const glm::vec3& up, float fov, float aspectRatio);
            ~Pinhole();

            [[nodiscard]] Ray GetRay(float u, float v) override;
    };

}

#endif //RT_PINHOLE_H
