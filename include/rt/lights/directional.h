
#ifndef RT_DIRECTIONAL_H
#define RT_DIRECTIONAL_H

#include <rt/lights/light.h>

namespace RT {

    class Directional : public ILight {
        public:
            explicit Directional(const glm::vec3& direction, float brightness = 1.0f, const glm::vec3& color = glm::vec3(1.0f));
            ~Directional() override;

            [[nodiscard]] glm::vec3 GetRadiance(const HitRecord &hitRecord, const SceneData &sceneData) override;
            [[nodiscard]] glm::vec3 GetDirection(const HitRecord& hitRecord) override;

        private:
            glm::vec3 _direction; // Direction the light comes from.

            float _brightness;
            glm::vec3 _color;
    };

}

#endif //RT_DIRECTIONAL_H
