
#ifndef RT_LAMBERTIAN_H
#define RT_LAMBERTIAN_H

#include <rt/brdf/brdf.h>

namespace RT {

    class Lambertian : public IBRDF {
        public:
            Lambertian(ISampler* sampler, const glm::vec3& diffuseColor, float diffuseCoefficient);
            ~Lambertian() override;

            [[nodiscard]] glm::vec3 GetBRDF(const HitRecord& hitRecord, const glm::vec3& incoming, const glm::vec3& outgoing) const override;
            [[nodiscard]] glm::vec3 SampleBRDF(const HitRecord& hitRecord, const glm::vec3& incoming, glm::vec3& outgoing) const override;
            [[nodiscard]] glm::vec3 GetReflectance(const HitRecord& hitRecord, const glm::vec3& outgoing) const override;

        private:
            float _diffuseCoefficient;
            glm::vec3 _diffuseColor;
    };

}

#endif //RT_LAMBERTIAN_H
