
#include <rt/lights/ambient_occluder.h>
#include <rt/objects/object.h>
#include <rt/samplers/multi_stratified.h>

namespace RT {

    AmbientOccluder::AmbientOccluder(float brightness, const glm::vec3 &color) : _color(color),
                                                                                 _brightness(brightness),
                                                                                 _minimumContribution(glm::vec3(0.0f)),
                                                                                 _sampler(new MultiStratified()),
                                                                                 _basis(glm::vec3(1.0f)) // Temporary.
                                                                                 {
        _sampler->SetCosinePower(1.0f); // Using normal cosine distribution.
        _sampler->Generate();
    }

    AmbientOccluder::~AmbientOccluder() {
        delete _sampler;
    }

    glm::vec3 AmbientOccluder::GetRadiance(const HitRecord &hitRecord, const SceneData &sceneData) {
        _basis = OrthonormalBasis(hitRecord.normal);

        Ray shadowRay;
        shadowRay.origin = hitRecord.point;
        shadowRay.direction = GetDirection(hitRecord);

        glm::vec3 color = _brightness * _color;

        if (IsShadowed(shadowRay, sceneData)) {
            color *= _minimumContribution;
        }

        return color;
    }

    glm::vec3 AmbientOccluder::GetDirection(const HitRecord &hitRecord) {
        glm::vec3 sample = _sampler->SampleUnitHemisphere();
        return _basis.GetLocalVector(sample);
    }

    bool AmbientOccluder::IsShadowed(const Ray &ray, const SceneData &sceneData) const {
        for (IObject* object : *sceneData.objects) {
            ShadowHitRecord hitRecord;
            if (object->Hit(ray, hitRecord)) {
                return true;
            }
        }

        return false;
    }
}
