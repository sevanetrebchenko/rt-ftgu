
#include <rt/lights/directional.h>

namespace RT {

    Directional::Directional(const glm::vec3 &direction, float brightness, const glm::vec3 &color) : _direction(direction),
                                                                                                     _brightness(brightness),
                                                                                                     _color(color)
                                                                                                     {
    }

    Directional::~Directional() = default;

    glm::vec3 Directional::GetRadiance(const HitRecord &hitRecord, const SceneData &sceneData) {
        return _brightness * _color;
    }

    glm::vec3 Directional::GetDirection(const HitRecord &hitRecord) {
        return _direction;
    }

}
