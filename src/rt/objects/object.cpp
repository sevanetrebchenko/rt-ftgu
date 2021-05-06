
#include <rt/objects/object.h>

namespace RT {

    IObject::IObject() : _color(glm::vec3(1.0f)) {
    }

    IObject::~IObject() = default;

}
