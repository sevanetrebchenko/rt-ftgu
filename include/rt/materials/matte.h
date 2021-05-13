
#ifndef RT_MATTE_H
#define RT_MATTE_H

#include <rt/materials/material.h>
#include <rt/brdf/lambertian.h>

namespace RT {

    class Matte : public IMaterial {
        public:
            explicit Matte(const glm::vec3& color, float ambientBrightness = 1.0f, float diffuseBrightness = 1.0f);
            ~Matte() override;

            [[nodiscard]] glm::vec3 GetRadiance(const Ray& ray, const HitRecord& hitRecord, const SceneData& sceneData) override;

        private:
            // Material BRDFs.
            Lambertian* _ambient;
            Lambertian* _diffuse;
    };

}

#endif //RT_MATTE_H
