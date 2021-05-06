
#include <rt/objects/primitives/plane.h>

namespace RT {

    Plane::Plane(const glm::vec3 &normal, const glm::vec3 &point) : IObject(),
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
        if (t < std::numeric_limits<float>::epsilon()) {
            return false;
        }

        // Valid intersection occurred.
        hitRecord.dt = t;
        hitRecord.normal = _normal;
        hitRecord.point = ray.StepTo(t);

        return true;
    }
}
