
#include <rt/lights/ambient.h>

namespace RT {

    Ambient::Ambient(float brightness, const glm::vec3 &color) : _brightness(brightness),
                                                                 _color(color)
                                                                 {
    }

    Ambient::~Ambient() = default;

    glm::vec3 Ambient::GetRadiance(const HitRecord &hitRecord) {
        return _brightness * _color;
    }

    glm::vec3 Ambient::GetDirection(const HitRecord &hitRecord) {
        std::cerr << "Calling GetDirection on ambient light - ambient lights have no direction." << std::endl;
        return glm::vec3(0.0f);
    }

    bool Ambient::IsShadowed(const Ray &ray, const SceneData &sceneData) const {
        return false; // Ambient lights produce no shadows.
    }
}
