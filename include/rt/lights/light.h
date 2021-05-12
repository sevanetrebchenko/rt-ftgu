
#ifndef RT_LIGHT_H
#define RT_LIGHT_H

#include <pch.h>
#include <rt/utilities/hit_record.h>

namespace RT {

    class ILight {
        public:
            ILight();
            virtual ~ILight();

            [[nodiscard]] virtual glm::vec3 GetRadiance(const HitRecord& hitRecord) = 0;
            [[nodiscard]] virtual glm::vec3 GetDirection(const HitRecord& hitRecord) = 0;

        protected:
            bool _projectShadows;
    };

}

#endif //RT_LIGHT_H