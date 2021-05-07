
#ifndef RT_THIN_LENS_H
#define RT_THIN_LENS_H

#include <rt/cameras/camera.h>

namespace RT {

    class ThinLens : public ICamera {
        public:
            ThinLens(const glm::vec3& position, const glm::vec3& lookat, const glm::vec3& up, float fov, float aspectRatio, float apertureLength, float focusDistance, ISampler* sampler);
            ~ThinLens();

            [[nodiscard]] Ray GetRay(float u, float v) override;

        private:
            ISampler* _sampler;
            float _lensRadius;
            float _focusDistance;
    };

}

#endif //RT_THIN_LENS_H
