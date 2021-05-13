
#include <rt/brdf/glossy.h>
#include <rt/samplers/multi_stratified.h>
#include <rt/utilities/onb.h>

namespace RT {

    Glossy::Glossy(ISampler *sampler,  const glm::vec3& specularColor, float specularCoefficient, float specularExponent) : IBRDF(new MultiStratified()),
                                                                                                                            _specularExponent(specularExponent),
                                                                                                                            _specularCoefficient(specularCoefficient),
                                                                                                                            _specularColor(specularColor),
                                                                                                                            _highlightSampler(sampler)
                                                                                                                            {
        sampler->SetCosinePower(specularExponent);
    }

    Glossy::~Glossy() {
        delete _highlightSampler;
    }

    // Used for direct illumination.
    glm::vec3 Glossy::GetBRDF(const HitRecord &hitRecord, const glm::vec3 &incoming, const glm::vec3 &outgoing) const {
        // Phong.
        glm::vec3 radiance(0.0f);
        float diffuseCoefficient = glm::dot(hitRecord.normal, incoming);
        glm::vec3 R = glm::normalize(2.0f * diffuseCoefficient * hitRecord.normal - incoming);

        float specularCoefficient = glm::dot(R, outgoing);

        if (specularCoefficient > 0.0f) {
            radiance = _specularColor * std::pow(specularCoefficient, _specularExponent);
        }

        return radiance;
    }

    // Used for indirect illumination.
    glm::vec3 Glossy::SampleBRDF(const HitRecord &hitRecord, const glm::vec3 &incoming, glm::vec3 &outgoing) const {
        float diffuseCoefficient = glm::dot(hitRecord.normal, incoming);
        glm::vec3 R = -incoming + 2.0f * diffuseCoefficient * hitRecord.normal;

        OrthonormalBasis onb(R);
        glm::vec3 sample = _highlightSampler->SampleUnitHemisphere();
        outgoing = glm::normalize(onb.GetLocalVector(sample));

        // Reflected ray is below the tangent plane.
        if (glm::dot(hitRecord.normal, outgoing) < 0.0f) {
            outgoing = glm::normalize(onb.GetLocalVector(-sample.x, -sample.y, sample.z));
        }

        float phong = std::pow(glm::dot(R, outgoing), _specularExponent);
        // pdf = phong * glm::dot(hitRecord.normal, outgoing);

        return (_specularCoefficient * _specularColor * phong);
    }

    glm::vec3 Glossy::GetReflectance(const HitRecord &hitRecord, const glm::vec3 &outgoing) const {
        return glm::vec3(0.0f); // Black.
    }
}
