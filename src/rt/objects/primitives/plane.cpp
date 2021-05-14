
#include <rt/objects/primitives/plane.h>

namespace RT {

    const float Plane::_epsilon = 0.001f;

    Plane::Plane(IMaterial* material, const glm::vec3 &normal, const glm::vec3 &point) : IObject(material),
                                                                                         _point(point),
                                                                                         _normal(normal)
                                                                                         {
    }

    Plane::~Plane() = default;

    bool Plane::Hit(const Ray &ray, HitRecord &hitRecord) const {
        float denom = (glm::dot(ray.direction, _normal));

        // Ray is parallel to plane.
        if (std::abs(denom) < std::numeric_limits<float>::epsilon()) {
            return false;
        }

        float t = glm::dot((_point - ray.origin), _normal) / denom;

        // Intersection happens before ray origin.
        if (t < _epsilon) {
            return false;
        }

        // Valid intersection occurred.
        hitRecord.dt = t;
        hitRecord.normal = _normal;
        hitRecord.point = ray.StepTo(t);
        hitRecord.material = _material;

        return true;
    }

    bool Plane::Hit(const Ray &ray, ShadowHitRecord &shadowHitRecord) const {
        HitRecord temp;
        bool hit = Hit(ray, temp);

        shadowHitRecord.dt = temp.dt;
        return hit;
    }
}
