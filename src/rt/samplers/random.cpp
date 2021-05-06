
#include <rt/samplers/random.h>

namespace RT {

    Random::Random(int numSamples, int numSampleSets) : ISampler(numSamples, numSampleSets) {

    }

    Random::~Random() = default;

    void Random::Generate() {
        std::vector<glm::vec2> samples;
        samples.reserve(_numSamples * _numSampleSets);

        for (int set = 0; set < _numSampleSets; ++set) {
            for (int i = 0; i < _numSamples; ++i) {
                samples.emplace_back(glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f));
            }
        }

        SetSamplePoints(samples);
    }

}
