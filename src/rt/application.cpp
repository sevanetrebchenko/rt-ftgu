
#include <rt/application.h>
#include <rt/utilities/ray.h>

// Objects.
#include <rt/objects/primitives/sphere.h>

namespace RT {

    Application::Application(const std::string& name, int width, int height) : _width(width),
                                                                               _height(height),
                                                                               _background(glm::vec3(0.0f)),
                                                                               _writer(new JPGWriter(name, width, height))
                                                                               {
    }

    void Application::Init() {
        _objects.push_back(new Sphere(glm::vec3(0.0f), 50.0f));
    }

    void Application::Run() {
        Render();
    }

    void Application::Shutdown() {
        for (IObject* object : _objects) {
            delete object;
        }

        delete _writer;
    }

    void Application::Render() const {
        float u, v;
        int lineCounter = _height;
        int samplesPerPixel = 10;
        int numRayBounces = 8;

        auto startTime = std::chrono::high_resolution_clock::now();

        for (int y = 0; y < _height; ++y) {
            std::cout << "rows remaining: " << lineCounter-- << " " << std::endl;

            for (int x = 0; x < _width; ++x) {
                glm::vec3 pixelColor(0.0f, 0.0f, 0.0f);

                pixelColor = Trace(Ray(glm::vec3(x, y, 100), glm::vec3(0.0f, 0.0f, -1.0f)));

//                // Antialiasing.
//                for (int sample = 0; sample < samplesPerPixel; ++sample) {
//                    u = ((float)x + glm::linearRand(0.0f, 1.0f)) / (float)(_width - 1);
//                    v = ((float)y + glm::linearRand(0.0f, 1.0f)) / (float)(_height - 1);
//
//                    pixelColor += RayColor(_camera.GetRay(u, v), numRayBounces);
//                }

                _writer->WriteColor(x, y, pixelColor);
            }
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> millis = endTime - startTime;
        std::cout << "time to render: " << millis.count() << "ms";
    }

    glm::vec3 Application::Trace(const Ray &ray) const {
        HitRecord hitRecord;

        for (IObject* object : _objects) {
            if (object->Hit(ray, hitRecord)) {
                return glm::vec3(1.0f, 0.0f, 0.0f);
            }
        }

        return _background;
    }
}