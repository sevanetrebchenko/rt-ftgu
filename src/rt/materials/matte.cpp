
#include <rt/materials/matte.h>
#include <rt/samplers/multi_stratified.h>

namespace RT {

    Matte::Matte(const glm::vec3& ambientColor, float ambientCoefficient, const glm::vec3& diffuseColor, float diffuseCoefficient) : IMaterial(),
                                                                                                                                   _ambient(new Lambertian(new MultiStratified(), ambientColor, ambientCoefficient)),
                                                                                                                                   _diffuse(new Lambertian(new MultiStratified(), diffuseColor, diffuseCoefficient))
                                                                                                                                   {
    }

    Matte::~Matte() {
        delete _ambient;
        delete _diffuse;
    }

    glm::vec3 Matte::GetRadiance(const Ray& ray, const HitRecord &hitRecord, const SceneData& sceneData) {
        glm::vec3 D = -ray.direction;
        glm::vec3 radiance = _ambient->GetReflectance(hitRecord, D) * sceneData._ambient->GetRadiance(hitRecord); // Start with ambient contribution.

        for (ILight* light : *sceneData._lights) {
            glm::vec3 L = light->GetDirection(hitRecord);
            float NdotL = glm::dot(hitRecord.normal, L);

            if (NdotL > 0.0f) {
                radiance += _diffuse->GetBRDF(hitRecord, D, L) * light->GetRadiance(hitRecord) * NdotL; // Diffuse Phong model.
            }
        }

        return radiance;
    }

}
