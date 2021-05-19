
#ifndef RT_LIGHT_H
#define RT_LIGHT_H

#include <pch.h>
#include <rt/utilities/ray.h>
#include <rt/utilities/scene_data.h>
#include <rt/utilities/hit_record.h>

namespace RT {

    class ILight {
        public:
            ILight();
            virtual ~ILight();

            [[nodiscard]] virtual glm::vec3 GetRadiance(const HitRecord &hitRecord, const SceneData &sceneData) = 0;
            [[nodiscard]] virtual glm::vec3 GetDirection(const HitRecord& hitRecord) = 0;
            [[nodiscard]] virtual bool IsShadowed(const Ray& ray, const SceneData& sceneData) const = 0;

            [[nodiscard]] bool CastsShadows() const;

        protected:
            bool _projectShadows;
    };

}

#endif //RT_LIGHT_H
