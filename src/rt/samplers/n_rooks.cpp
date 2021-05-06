
#include <rt/samplers/n_rooks.h>

namespace RT {

    NRooks::NRooks(int numSamples, int numSampleSets) : ISampler(numSamples, numSampleSets) {
    }

    NRooks::~NRooks() = default;

    void NRooks::Generate() {
        std::vector<glm::vec2> samples;
        samples.reserve(_numSamples * _numSampleSets);

        for (int set = 0; set < _numSampleSets; ++set) {
            for (int i = 0; i < _numSamples; ++i) {
                samples.emplace_back(((float) i + glm::linearRand(0.0f, 1.0f)) / (float) _numSamples,
                                      ((float) i + glm::linearRand(0.0f, 1.0f)) / (float) _numSamples);
            }
        }

        Shuffle(samples);
        SetSamplePoints(samples);
    }
}