
#ifndef RT_OBJECT_H
#define RT_OBJECT_H

#include <pch.h>
#include <rt/utilities/ray.h>
#include <rt/utilities/hit_record.h>
#include <rt/materials/material.h>

namespace RT {

    class IObject {
        public:
            explicit IObject(IMaterial* material);
            virtual ~IObject();

            virtual bool Hit(const Ray& ray, HitRecord& hitRecord) const = 0;
            IMaterial* GetMaterial() const;

        protected:
            IMaterial* _material;
    };

}

#endif //RT_OBJECT_H
