
#include <rt/application.h>
#include <rt/utilities/ray.h>

#include <rt/cameras/pinhole.h>
#include <rt/samplers/multi_stratified.h>

// Objects.
#include <rt/objects/primitives/sphere.h>
#include <rt/objects/primitives/plane.h>

// Lights.
#include <rt/lights/ambient.h>
#include <rt/lights/point.h>
#include <rt/lights/directional.h>
#include <rt/lights/ambient_occluder.h>

// Materials.
#include <rt/materials/matte.h>
#include <rt/materials/phong.h>

namespace RT {

    Application::Application(const std::string& name, int width, int height) : _width(width),
                                                                               _height(height),
                                                                               _background(glm::vec3(0.0f)),
                                                                               _writer(new JPGWriter(name, width, height)),
                                                                               _camera(new Pinhole(glm::vec3(0.0f, 0.0f, 100.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 20.0f, (float)_width / (float)_height)),
                                                                               _sampler(new MultiStratified())
                                                                               {
    }

    void Application::Init() {
        _sampler->Generate();

        // Lights.
        _ambient = new AmbientOccluder(1.0f, glm::vec3(1.0f));
//        _lights.push_back(new Point(glm::vec3(8.0f, 8.0f, 8.0f), 2.0f));
//        lights.push_back(new Directional(glm::vec3(1.0f, 0.0f, 1.0f)));

        // Objects.
        _objects.push_back(new Sphere(new Phong(glm::vec3(0.0f), 1.0f, glm::vec3(1.0f, 0.0f, 0.0f), 1.0f, glm::vec3(1.0f), 1.0f, 15.0f), glm::vec3(0.0f), 5.0f));
        _objects.push_back(new Sphere(new Matte(glm::vec3(0.1f), 1.0f, glm::vec3(1.0f), 1.0f), glm::vec3(-10.0f, 0.0f, -4.0f), 6.0f));
        _objects.push_back(new Plane(new Matte(glm::vec3(0.1f), 1.0f, glm::vec3(0.5f), 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -6.0f, 0.0f)));
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
                _writer->WriteColor(x, y, radiance);
            }
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> millis = endTime - startTime;
        std::cout << "time to render: " << millis.count() << "ms";
    }

    glm::vec3 Application::Trace(const Ray &ray) const {
        HitRecord hitRecord;

        bool hit = false;
        float nearest = std::numeric_limits<float>::max();

        // Intersect with all objects to get the nearest intersection.
        for (IObject* object : _objects) {
            HitRecord temp;

            if (object->Hit(ray, temp) && (temp.dt < nearest)) {
                hit = true;
                nearest = temp.dt;
                hitRecord = temp;
            }
        }

        if (!hit) {
            return _background;
        }

        SceneData sceneData;
        sceneData.ambient = _ambient;
        sceneData.lights = &_lights;
        sceneData.objects = &_objects;

        return hitRecord.material->GetRadiance(ray, hitRecord, sceneData);
    }
}
