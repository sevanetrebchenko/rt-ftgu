
#include <rt/objects/primitives/sphere.h>

namespace RT {

    Sphere::Sphere(const glm::vec3 &center, float radius) : IObject(),
                                                            _center(center),
                                                            _radius(radius)
                                                            {
    }

    Sphere::~Sphere() = default;

    bool Sphere::Hit(const Ray &ray, HitRecord &hitRecord) const {
        glm::vec3 temp = ray.origin - _center;
        float a = glm::dot(ray.direction, ray.direction);
        float b = 2.0f * glm::dot(temp, ray.direction);
        float c = glm::dot(temp, temp) - (_radius * _radius);

        float discriminant = b * b - 4.0f * a * c;

        // Quadratic equation has no real solution, hence no intersection.
        if (discriminant < 0.0f) {
            return false;
        }

        float t;
        discriminant = std::sqrt(discriminant);
        float denominator = 2.0f * a;

        // Check smaller root.
        t = (-b - discriminant) / denominator;

        // Intersection at first root.
        if (t > std::numeric_limits<float>::epsilon()) {
            glm::vec3 point = ray.StepTo(t);

            hitRecord.dt = t;
            hitRecord.point = point;
            hitRecord.normal = glm::normalize((point - _center) / _radius);

            return true;
        }

        // Check larger root.
        t = (-b + discriminant) / denominator;

        // Intersection at second root.
        if (t > std::numeric_limits<float>::epsilon()) {
            glm::vec3 point = ray.StepTo(t);

            hitRecord.dt = t;
            hitRecord.point = point;
            hitRecord.normal = glm::normalize((point - _center) / _radius);

            return true;
        }

        return false;
    }
}
