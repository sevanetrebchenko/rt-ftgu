
#ifndef RT_APPLICATION_H
#define RT_APPLICATION_H

#include <rt/utilities/writer.h>
#include <rt/objects/object.h>

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

            glm::vec3 _background;
            std::vector<IObject*> _objects;
    };

}

#endif //RT_APPLICATION_H
