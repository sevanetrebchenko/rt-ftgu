
#include <rt/cameras/pinhole.h>

namespace RT {


    Pinhole::Pinhole(const glm::vec3 &position, const glm::vec3 &lookat, const glm::vec3 &up, float fov, float aspectRatio) : ICamera(position, lookat, up, fov, aspectRatio) {
    }

    Pinhole::~Pinhole() = default;

    Ray Pinhole::GetRay(float u, float v) {
        return Ray(_position, _origin + u * _horizontal - v * _vertical - _position);
    }

}
