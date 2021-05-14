
#ifndef RT_PLANE_H
#define RT_PLANE_H

#include <rt/objects/object.h>

namespace RT {

    class Plane : public IObject {
        public:
            Plane(IMaterial* material, const glm::vec3& normal, const glm::vec3& point);
            ~Plane() override;

            [[nodiscard]] bool Hit(const Ray& ray, HitRecord& hitRecord) const override;
            [[nodiscard]] bool Hit(const Ray& ray, ShadowHitRecord& shadowHitRecord) const override;

        private:
            static const float _epsilon;
            glm::vec3 _point;
            glm::vec3 _normal;
    };

}

#endif //RT_PLANE_H
