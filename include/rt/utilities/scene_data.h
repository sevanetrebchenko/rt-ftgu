
#ifndef RT_SCENE_DATA_H
#define RT_SCENE_DATA_H

#include <pch.h>

namespace RT {

    // Forward declarations.
    class ILight;
    class IObject;

    struct SceneData {
        SceneData();
        ~SceneData();

        ILight* ambient;
        std::vector<ILight*>* lights;
        std::vector<IObject*>* objects;
    };

}

#endif //RT_SCENE_DATA_H
