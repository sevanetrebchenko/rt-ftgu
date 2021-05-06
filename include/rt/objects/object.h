
#ifndef RT_OBJECT_H
#define RT_OBJECT_H

#include <pch.h>
#include <rt/utilities/ray.h>
#include <rt/utilities/hit_record.h>

namespace RT {

    class IObject {
        public:
            IObject();
            virtual ~IObject();

            virtual bool Hit(const Ray& ray, HitRecord& hitRecord) const = 0;

        protected:
            glm::vec3 _color;

        private:

    };

}

#endif //RT_OBJECT_H
