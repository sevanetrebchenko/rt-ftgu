
#include <rt/materials/matte.h>
#include <rt/samplers/multi_stratified.h>
#include <rt/lights/light.h>

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
        glm::vec3 radiance = _ambient->GetReflectance(hitRecord, D) * sceneData.ambient->GetRadiance(hitRecord, sceneData); // Start with ambient contribution.

        for (ILight* light : *sceneData.lights) {
            glm::vec3 L = light->GetDirection(hitRecord);
            float NdotL = glm::dot(hitRecord.normal, L);

            if (NdotL > 0.0f) {
                bool shadowed = false;

                if (light->CastsShadows()) {
                    Ray shadowRay(hitRecord.point, L);
                    shadowed = light->IsShadowed(shadowRay, sceneData);
                }

                if (!shadowed) {
                    radiance += _diffuse->GetBRDF(hitRecord, D, L) * light->GetRadiance(hitRecord, sceneData) * NdotL; // Diffuse Phong model.
                }
            }
        }

        return radiance;
    }

}
