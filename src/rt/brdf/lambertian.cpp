
#include <rt/brdf/lambertian.h>
#include <rt/utilities/onb.h>

namespace RT {

    Lambertian::Lambertian(ISampler* sampler, const glm::vec3& diffuseColor, float diffuseCoefficient) : IBRDF(sampler),
                                                                                                         _diffuseCoefficient(diffuseCoefficient),
                                                                                                         _diffuseColor(diffuseColor)
                                                                                                         {
    }

    Lambertian::~Lambertian() = default;

    glm::vec3 Lambertian::GetBRDF(const HitRecord &hitRecord, const glm::vec3 &incoming, const glm::vec3 &outgoing) const {
        return _diffuseCoefficient * _diffuseColor * (float)M_1_PI;
    }

    glm::vec3 Lambertian::SampleBRDF(const HitRecord &hitRecord, const glm::vec3 &incoming, glm::vec3 &outgoing) const {
        // Generate ONB relative to the hit normal.
        OrthonormalBasis onb(hitRecord.normal);

        glm::vec3 sample = _sampler->SampleUnitHemisphere();
        outgoing = glm::normalize(onb.GetLocalVector(sample));

        // pdf = hitRecord.normal * outgoing * (float)M_1_PI;
        return GetBRDF(hitRecord, incoming, outgoing);
    }

    glm::vec3 Lambertian::GetReflectance(const HitRecord &hitRecord, const glm::vec3 &outgoing) const {
        return _diffuseCoefficient * _diffuseColor;
    }

}
