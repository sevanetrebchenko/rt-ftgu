
#include <rt/materials/material.h>

namespace RT {

    IMaterial::IMaterial() = default;

    IMaterial::~IMaterial() = default;

    glm::vec3 IMaterial::GetRadiance(const Ray& ray, const HitRecord &hitRecord, const SceneData& sceneData) {
        return glm::vec3(0.0f); // Black.
    }
}
