
#ifndef RT_GLOSSY_H
#define RT_GLOSSY_H

#include <rt/brdf/brdf.h>

namespace RT {

    class Glossy : public IBRDF {
        public:
            Glossy(ISampler* sampler, const glm::vec3& specularColor, float specularCoefficient, float specularExponent);
            ~Glossy() override;

            [[nodiscard]] glm::vec3 GetBRDF(const HitRecord& hitRecord, const glm::vec3& incoming, const glm::vec3& outgoing) const override;
            [[nodiscard]] glm::vec3 SampleBRDF(const HitRecord& hitRecord, const glm::vec3& incoming, glm::vec3& outgoing) const override;
            [[nodiscard]] glm::vec3 GetReflectance(const HitRecord& hitRecord, const glm::vec3& outgoing) const override;

        private:
            float _specularExponent;
            float _specularCoefficient;
            glm::vec3 _specularColor;

            ISampler* _highlightSampler;
    };

}

#endif //RT_GLOSSY_H
