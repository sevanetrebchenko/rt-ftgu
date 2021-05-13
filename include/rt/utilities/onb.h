
#ifndef RT_ONB_H
#define RT_ONB_H

#include <pch.h>

namespace RT {

    class OrthonormalBasis {
        public:
            explicit OrthonormalBasis(const glm::vec3& normal);
            ~OrthonormalBasis();

            [[nodiscard]] glm::vec3 GetLocalVector(const glm::vec3& input) const;
            [[nodiscard]] glm::vec3 GetLocalVector(float x, float y, float z) const;

        private:
            glm::vec3 _axes[3];
    };

}

#endif //RT_ONB_H
