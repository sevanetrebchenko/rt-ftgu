
#include <rt/cameras/thin_lens.h>

namespace RT {


    ThinLens::ThinLens(const glm::vec3 &position, const glm::vec3 &lookat, const glm::vec3 &up, float fov, float aspectRatio, float apertureLength, float focusDistance, ISampler *sampler) : ICamera(position, lookat, up, fov, aspectRatio),
                                                                                                                                                                                              _lensRadius(apertureLength / 2.0f),
                                                                                                                                                                                              _focusDistance(focusDistance),
                                                                                                                                                                                              _sampler(sampler)
                                                                                                                                                                                              {
        _sampler->Generate();
    }

    ThinLens::~ThinLens() {
        delete _sampler;
    }

    Ray ThinLens::GetRay(float u, float v) {
        // Focus blur with depth of field.
        glm::vec3 direction = _lensRadius * glm::vec3(_sampler->SampleUnitDisk(), 0.0f);

        // Start the ray offset a little around a disk surrounding the camera eye for it to purposefully "miss".
        // Rays that intersect sufficiently close to the focus distance will appear in focus.
        glm::vec3 startingRayPosition = _position + _horizontal * direction.x + _vertical * direction.y;

        return Ray(startingRayPosition, _origin + u * _horizontal - v * _vertical - startingRayPosition);
    }

}
