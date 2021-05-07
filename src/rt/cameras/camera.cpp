
#include <rt/cameras/camera.h>

namespace RT {

    ICamera::ICamera(const glm::vec3 &position, const glm::vec3 &lookat, const glm::vec3 &up, float fov, float aspectRatio) : _position(position),
                                                                                                                              _lookat(lookat),
                                                                                                                              _up(up),
                                                                                                                              _fov(fov),
                                                                                                                              _aspectRatio(aspectRatio)
                                                                                                                              {
        float theta = glm::radians(_fov);
        float height = std::tan(theta / 2.0f);

        float viewportHeight = 2.0f * height;
        float viewportWidth = viewportHeight * _aspectRatio;

        _w = glm::normalize(_position - _lookat); // Forward.
        _v = glm::normalize(glm::cross(_up, _w)); // Right.
        _u = glm::normalize(glm::cross(_w, _v));  // Up.

        _horizontal = viewportWidth * _v;
        _vertical = viewportHeight * _u;
        _origin = _position - _horizontal / 2.0f + _vertical / 2.0f - _w;
    }

    ICamera::~ICamera() = default;

}
