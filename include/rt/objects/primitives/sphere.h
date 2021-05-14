
#ifndef RT_SPHERE_H
#define RT_SPHERE_H

#include <pch.h>
#include <rt/objects/object.h>

namespace RT {

    class Sphere : public IObject {
        public:
            Sphere(IMaterial* material, const glm::vec3& center, float radius);
            ~Sphere() override;

            [[nodiscard]] bool Hit(const Ray& ray, HitRecord& hitRecord) const override;
            [[nodiscard]] bool Hit(const Ray& ray, ShadowHitRecord& shadowHitRecord) const override;

        private:
            static const float _epsilon;
            glm::vec3 _center;
            float _radius;
    };

}

#endif //RT_SPHERE_H
