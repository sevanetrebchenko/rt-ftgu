
#ifndef RT_RANDOM_H
#define RT_RANDOM_H

#include <pch.h>

namespace RT {

    template <typename T>
    [[nodiscard]] T Random(T min = 0, T max = std::numeric_limits<T>::infinity()) {
        return glm::linearRand(min, max);
    }

}

#endif //RT_RANDOM_H
