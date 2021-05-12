
#ifndef RT_AMBIENT_H
#define RT_AMBIENT_H

#include <rt/lights/light.h>

namespace RT {

    class Ambient : public ILight {
        public:
            explicit Ambient(float brightness = 1.0f, const glm::vec3& color = glm::vec3(1.0f));
            ~Ambient() override;

            [[nodiscard]] glm::vec3 GetRadiance(const HitRecord& hitRecord) override;
            [[nodiscard]] glm::vec3 GetDirection(const HitRecord& hitRecord) override;

        private:
            float _brightness;
            glm::vec3 _color;
    };

}

#endif //RT_AMBIENT_H
