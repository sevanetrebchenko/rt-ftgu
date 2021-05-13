
#include <rt/objects/object.h>

namespace RT {

    IObject::IObject(IMaterial* material) : _material(material) {
    }

    IObject::~IObject() {
        delete _material;
    }

    IMaterial *IObject::GetMaterial() const {
        return _material;
    }

}
