
#ifndef RT_BRDF_H
#define RT_BRDF_H

#include <pch.h>
#include <rt/samplers/sampler.h>
#include <rt/utilities/hit_record.h>

namespace RT {

    class IBRDF {
        public:
            IBRDF(ISampler* sampler);
            virtual ~IBRDF();

            // Get this BRDF.
            [[nodiscard]] virtual glm::vec3 GetBRDF(const HitRecord& hitRecord, const glm::vec3& incoming, const glm::vec3& outgoing) const = 0;

            // Compute the direction of reflected rays (outgoing).
            [[nodiscard]] virtual glm::vec3 SampleBRDF(const HitRecord& hitRecord, const glm::vec3& incoming, glm::vec3& outgoing) const = 0;

            // Get hemispherical reflectance for the outgoing direction.
            [[nodiscard]] virtual glm::vec3 GetReflectance(const HitRecord& hitRecord, const glm::vec3& outgoing) const = 0;

        protected:
            ISampler* _sampler;
    };

}

#endif //RT_BRDF_H
