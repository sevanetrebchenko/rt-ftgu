
#include <rt/lights/point.h>
#include <rt/objects/object.h>

namespace RT {

    Point::Point(const glm::vec3 &position, float brightness, const glm::vec3 &color) : _position(position),
                                                                                        _brightness(brightness),
                                                                                        _color(color)
                                                                                        {
    }

    Point::~Point() = default;

    glm::vec3 Point::GetRadiance(const HitRecord &hitRecord, const SceneData &sceneData) {
        return _brightness * _color;
    }

    glm::vec3 Point::GetDirection(const HitRecord &hitRecord) {
        return glm::normalize(_position - hitRecord.point);
    }

    // Determines if the given ray is in the shadow of this light or not.
    bool Point::IsShadowed(const Ray &ray, const SceneData& sceneData) const {
        float max = glm::distance(_position, ray.origin);

        for (IObject* object : *sceneData.objects) {
            ShadowHitRecord hitRecord;
            if (object->Hit(ray, hitRecord) && hitRecord.dt < max) {
                return true;
            }
        }

        return false;
    }

}
