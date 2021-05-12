
#include <rt/lights/point.h>

namespace RT {

    Point::Point(const glm::vec3 &position, float brightness, const glm::vec3 &color) : _position(position),
                                                                                        _brightness(brightness),
                                                                                        _color(color)
                                                                                        {
    }

    Point::~Point() = default;

    glm::vec3 Point::GetRadiance(const HitRecord &hitRecord) {
        return _brightness * _color;
    }

    glm::vec3 Point::GetDirection(const HitRecord &hitRecord) {
        return glm::normalize(_position - hitRecord.point);
    }

}
