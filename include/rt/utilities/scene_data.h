
#ifndef RT_SCENE_DATA_H
#define RT_SCENE_DATA_H

#include <pch.h>
#include <rt/lights/light.h>

namespace RT {

    struct SceneData {
        SceneData();
        ~SceneData();

        ILight* _ambient;
        std::vector<ILight*>* _lights;
    };

}

#endif //RT_SCENE_DATA_H
