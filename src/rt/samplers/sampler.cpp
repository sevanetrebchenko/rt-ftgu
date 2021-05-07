
#include <pch.h>
#include <rt/samplers/sampler.h>
#include <rt/utilities/random.h>

#include <random>

namespace RT {

    ISampler::ISampler(int numSamples, int numSampleSets) : _numSamples(numSamples),
                                                            _numSampleSets(numSampleSets),
                                                            _cosinePower(0.0f), // Start off using the entire hemisphere.
                                                            _sampleCount(0),
                                                            _indexJump(0)
                                                            {
        InitShuffledIndices();
    }

    ISampler::~ISampler() = default;

    void ISampler::SetCosinePower(float power) {
        _cosinePower = power;
    }

    void ISampler::InitShuffledIndices() {
        std::vector<unsigned> indices;
        indices.reserve(_numSamples);

        // Create initial set of indices.
        for (int i = 0; i < _numSamples; ++i) {
            indices.push_back(i);
        }

        for (int set = 0; set < _numSampleSets; ++set) {
            // Shuffle indices.
            std::shuffle(indices.begin(), indices.end(), std::mt19937(std::random_device()()));

            // Emplace shuffled indices.
            for (int i = 0; i < _numSamples; ++i) {
                _indices.push_back(indices[i]);
            }
        }
    }

    void ISampler::Shuffle(std::vector<glm::vec2>& samples) {
        // Shuffle x-coordinates.
        for (int set = 0; set < _numSampleSets; ++set) {
            for (int i = 0; i < _numSamples - 1; ++i) {
                int target = Random<int>() % _numSamples + set * _numSamples;
                std::swap(samples[i + set * _numSamples + 1].x, samples[target].x);
            }
        }

        // Shuffle y-coordinates.
        for (int set = 0; set < _numSampleSets; ++set) {
            for (int i = 0; i < _numSamples - 1; ++i) {
                int target = Random<int>() % _numSamples + set * _numSamples;
                std::swap(samples[i + set * _numSamples + 1].y, samples[target].y);
            }
        }
    }

    const glm::vec2& ISampler::SampleUnitSquare() {
        return _squareSamples[GetNextSampleIndex()];
    }

    const glm::vec2& ISampler::SampleUnitDisk() {
        return _diskSamples[GetNextSampleIndex()];
    }

    const glm::vec3 &ISampler::SampleUnitHemisphere() {
        return _hemisphereSamples[GetNextSampleIndex()];
    }

    [[nodiscard]] int ISampler::GetNextSampleIndex() {
        // Sampled an entire pixel, offset random jump so horizontal and vertical pixels don't share the same sample pattern.
        if (_sampleCount % _numSamples == 0) {
            _indexJump = (Random<int>() % _numSampleSets) * _numSamples;
        }

        // Offset using index map for consecutive accesses to not return the same values.
        return _indexJump + _indices[_indexJump + _sampleCount++ % _numSamples];
    }

    void ISampler::SetSamplePoints(std::vector<glm::vec2> &samples) {
        _squareSamples = std::move(samples);

        // Construct mappings for various uses of the samples.
        MapToDisk();
        MapToHemisphere();
    }

    void ISampler::MapToDisk() {
        int num = _squareSamples.size();
        float radius;
        float phi;
        glm::vec2 sample;

        _diskSamples.resize(num);

        // Using Peter Shirley's concentric circle method.
        for (int i = 0; i < num; ++i) {
            // Map sample point to [-1, 1] x [-1, 1]
            sample = _squareSamples[i];
            sample = (sample - 0.5f) * 2.0f;

            if (sample.x > -sample.y) {
                if (sample.x > sample.y) {
                    // Sector 1.
                    radius = sample.x;
                    phi = sample.y / sample.x;
                }
                else {
                    // Sector 2.
                    radius = sample.y;
                    phi = 2.0f - sample.x / sample.y;
                }
            }
            else {
                if (sample.x < sample.y) {
                    // Sector 3.
                    radius = -sample.x;
                    phi = 4.0f + sample.y / sample.x;
                }
                else {
                    // Sector 4.
                    radius = -sample.y;

                    // Avoid division by 0.
                    if (std::abs(sample.y) > std::numeric_limits<float>::epsilon()) {
                        phi = 6.0f - sample.x / sample.y;
                    }
                    else {
                        phi = 0.0f;
                    }
                }
            }

            phi *= (float)M_PI_4;

            _diskSamples[i].x = radius * std::cos(phi);
            _diskSamples[i].y = radius * std::sin(phi);
        }
    }

    void ISampler::MapToHemisphere() {
        int num = _squareSamples.size();
        _hemisphereSamples.reserve(num);

        float pi = (float)M_PI;

        for (int i = 0; i < num; ++i) {
            const glm::vec2& sample = _squareSamples[i];

            float cosPhi = std::cos(2.0f * pi * sample.x);
            float sinPhi = std::sin(2.0f * pi * sample.x);

            float cosTheta = std::pow(1.0f - sample.y, 1.0f / (_cosinePower + 1.0f));
            float sinTheta = std::sqrt(1.0f - cosTheta * cosTheta);

            _hemisphereSamples.emplace_back(sinTheta * cosPhi, sinTheta * sinPhi, cosTheta);
        }
    }

    int ISampler::GetNumSamples() const {
        return _numSamples;
    }

    int ISampler::GetNumSampleSets() const {
        return _numSampleSets;
    }

}
