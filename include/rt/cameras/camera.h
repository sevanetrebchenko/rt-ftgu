
#ifndef RT_CAMERA_H
#define RT_CAMERA_H

#include <pch.h>
#include <rt/samplers/sampler.h>
#include <rt/utilities/ray.h>

namespace RT {

    class ICamera {
        public:
            ICamera(const glm::vec3& position, const glm::vec3& lookat, const glm::vec3& up, float fov, float aspectRatio);
            ~ICamera();

            [[nodiscard]] virtual Ray GetRay(float u, float v) = 0;

        protected:
            glm::vec3 _position;
            glm::vec3 _lookat;
            glm::vec3 _up;

            // Orthonormal basis vectors.
            glm::vec3 _u;
            glm::vec3 _v;
            glm::vec3 _w;

            glm::vec3 _horizontal;
            glm::vec3 _vertical;
            glm::vec3 _origin;

            float _fov;
            float _aspectRatio;
    };
}

#endif //RT_CAMERA_H
