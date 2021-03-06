
#ifndef RT_MATERIAL_H
#define RT_MATERIAL_H

#include <pch.h>
#include <rt/utilities/ray.h>
#include <rt/utilities/scene_data.h>
#include <rt/utilities/hit_record.h>

namespace RT {

    class IMaterial {
        public:
            IMaterial();
            virtual ~IMaterial();

            [[nodiscard]] virtual glm::vec3 GetRadiance(const Ray& ray, const HitRecord& hitRecord, const SceneData& sceneData);
    };

}

#endif //RT_MATERIAL_H
