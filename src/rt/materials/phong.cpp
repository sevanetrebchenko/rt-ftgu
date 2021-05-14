
#include <rt/materials/phong.h>
#include <rt/samplers/multi_stratified.h>
#include <rt/lights/light.h>

namespace RT {

    Phong::Phong(const glm::vec3 &ambientColor, float ambientCoefficient,
                 const glm::vec3 &diffuseColor, float diffuseCoefficient,
                 const glm::vec3 &specularColor, float specularCoefficient, float specularExponent) : _ambient(new Lambertian(new MultiStratified(), ambientColor, ambientCoefficient)),
                                                                                                      _diffuse(new Lambertian(new MultiStratified(), diffuseColor, diffuseCoefficient)),
                                                                                                      _specular(new Glossy(new MultiStratified(), specularColor, specularCoefficient, specularExponent))
                                                                                                      {

    }

    Phong::~Phong() {
        delete _ambient;
        delete _diffuse;
        delete _specular;
    }

    glm::vec3 Phong::GetRadiance(const Ray &ray, const HitRecord &hitRecord, const SceneData &sceneData) {
        glm::vec3 D = -ray.direction;
        glm::vec3 radiance = _ambient->GetReflectance(hitRecord, D) * sceneData.ambient->GetRadiance(hitRecord); // Start with ambient contribution.

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
                    radiance += (_diffuse->GetBRDF(hitRecord, D, L) + _specular->GetBRDF(hitRecord, D, L)) * light->GetRadiance(hitRecord) * NdotL; // Diffuse Phong model.
                }
            }
        }

        return radiance;
    }

}
