
#ifndef RT_APPLICATION_H
#define RT_APPLICATION_H

#include <rt/utilities/writer.h>
#include <rt/objects/object.h>
#include <rt/cameras/camera.h>
#include <rt/samplers/sampler.h>
#include <rt/lights/light.h>

namespace RT {

    class Application {
        public:
            Application(const std::string& name, int width, int height);

            void Init();
            void Run();
            void Shutdown();

        private:
            void Render() const;
            [[nodiscard]] glm::vec3 Trace(const Ray& ray) const;

            int _width;
            int _height;
            IWriter* _writer;
            ICamera* _camera;
            ISampler* _sampler;

            glm::vec3 _background;

            // Scene data.
            ILight* _ambient; // Only one ambient light per scene.
            std::vector<IObject*> _objects;
            mutable std::vector<ILight*> _lights;
    };

}

#endif //RT_APPLICATION_H
