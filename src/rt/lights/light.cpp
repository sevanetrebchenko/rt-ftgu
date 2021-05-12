
#include <rt/lights/light.h>

namespace RT {

    ILight::ILight() : _projectShadows(true) {
    }

    ILight::~ILight() = default;

}
