
#ifndef RT_MATTE_H
#define RT_MATTE_H

#include <rt/materials/material.h>
#include <rt/brdf/lambertian.h>

namespace RT {

    class Matte : public IMaterial {
        public:
            Matte(const glm::vec3& ambientColor, float ambientCoefficient, const glm::vec3& diffuseColor, float diffuseCoefficient);
            ~Matte() override;

            [[nodiscard]] glm::vec3 GetRadiance(const Ray& ray, const HitRecord& hitRecord, const SceneData& sceneData) override;

        private:
            // Material BRDFs.
            Lambertian* _ambient;
            Lambertian* _diffuse;
    };

}

#endif //RT_MATTE_H
