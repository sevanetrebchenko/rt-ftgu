
#ifndef RT_POINT_H
#define RT_POINT_H

#include <rt/lights/light.h>
#include <rt/utilities/hit_record.h>

namespace RT {

    class Point : public ILight {
        public:
            explicit Point(const glm::vec3& position, float brightness = 1.0f, const glm::vec3& color = glm::vec3(1.0f));
            ~Point() override;

            [[nodiscard]] glm::vec3 GetRadiance(const HitRecord& hitRecord) override;
            [[nodiscard]] glm::vec3 GetDirection(const HitRecord& hitRecord) override;

            [[nodiscard]] bool IsShadowed(const Ray& ray, const SceneData& sceneData) const override;

        private:
            glm::vec3 _position;

            float _brightness;
            glm::vec3 _color;
    };

}

#endif //RT_POINT_H
