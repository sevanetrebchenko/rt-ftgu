
#include <rt/application.h>
#include <rt/utilities/ray.h>

#include <rt/cameras/pinhole.h>
#include <rt/samplers/multi_stratified.h>

// Objects.
#include <rt/objects/primitives/sphere.h>

// Lights.
#include <rt/lights/ambient.h>
#include <rt/lights/point.h>
#include <rt/lights/directional.h>

namespace RT {

    Application::Application(const std::string& name, int width, int height) : _width(width),
                                                                               _height(height),
                                                                               _background(glm::vec3(0.0f)),
                                                                               _writer(new JPGWriter(name, width, height)),
                                                                               _camera(new Pinhole(glm::vec3(0.0f, 0.0f, 100.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 20.0f, (float)_width / (float)_height)),
                                                                               _sampler(new MultiStratified(36, 83))
                                                                               {
    }

    void Application::Init() {
        _sampler->Generate();

        _ambient = new Ambient();

        _objects.push_back(new Sphere(glm::vec3(0.0f), 5.0f));
        _objects.push_back(new Sphere(glm::vec3(-5.0f, 0.0f, -5.0f), 5.0f));
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
        int lineCounter = _height;
        int numRayBounces = 8;

        auto startTime = std::chrono::high_resolution_clock::now();
        int numSamples = _sampler->GetNumSamples();

        for (int y = 0; y < _height; ++y) {
            std::cout << "rows remaining: " << lineCounter-- << " " << std::endl;

            for (int x = 0; x < _width; ++x) {
                glm::vec3 radiance(0.0f, 0.0f, 0.0f);

                for (int s = 0; s < numSamples; ++s) {
                    const glm::vec2& sample = _sampler->SampleUnitSquare();
                    float u = ((float)x + sample.x) / (float)(_width - 1);
                    float v = ((float)y + sample.y) / (float)(_height - 1);

                    radiance += Trace(_camera->GetRay(u, v));
                }

                radiance /= (float)numSamples;


//                // Antialiasing.
//                for (int sample = 0; sample < samplesPerPixel; ++sample) {
//                    u = ((float)x + glm::linearRand(0.0f, 1.0f)) / (float)(_width - 1);
//                    v = ((float)y + glm::linearRand(0.0f, 1.0f)) / (float)(_height - 1);
//
//                    pixelColor += RayColor(_camera.GetRay(u, v), numRayBounces);
//                }

                _writer->WriteColor(x, y, radiance);
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
