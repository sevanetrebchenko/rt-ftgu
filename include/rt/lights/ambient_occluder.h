
#ifndef RT_AMBIENT_OCCLUDER_H
#define RT_AMBIENT_OCCLUDER_H

#include <rt/lights/light.h>
#include <rt/utilities/onb.h>
#include <rt/samplers/sampler.h>

namespace RT {

    class AmbientOccluder : public ILight {
        public:
            explicit AmbientOccluder(float brightness = 1.0f, const glm::vec3& color = glm::vec3(1.0f));
            ~AmbientOccluder() override;

            [[nodiscard]] glm::vec3 GetRadiance(const HitRecord &hitRecord, const SceneData &sceneData) override;
            [[nodiscard]] glm::vec3 GetDirection(const HitRecord& hitRecord) override;
            [[nodiscard]] bool IsShadowed(const Ray& ray, const SceneData& sceneData) const override;

        private:
            OrthonormalBasis _basis;
            float _brightness;
            glm::vec3 _minimumContribution; // Minimum contribution that is not black for fully occluded pixels.
            glm::vec3 _color;
            ISampler* _sampler;
    };

}

#endif //RT_AMBIENT_OCCLUDER_H
