
#ifndef RT_PHONG_H
#define RT_PHONG_H

#include <rt/materials/material.h>
#include <rt/brdf/lambertian.h>
#include <rt/brdf/glossy.h>

namespace RT {

    class Phong : public IMaterial {
        public:
            Phong(const glm::vec3& ambientColor, float ambientCoefficient,
                  const glm::vec3& diffuseColor, float diffuseCoefficient,
                  const glm::vec3& specularColor, float specularCoefficient, float specularExponent);
            ~Phong() override;

            [[nodiscard]] glm::vec3 GetRadiance(const Ray& ray, const HitRecord& hitRecord, const SceneData& sceneData) override;

        private:
            Lambertian* _ambient;
            Lambertian* _diffuse;
            Glossy* _specular;
    };

}

#endif //RT_PHONG_H
