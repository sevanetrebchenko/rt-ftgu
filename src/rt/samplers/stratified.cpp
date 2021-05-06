
#include <rt/samplers/stratified.h>

namespace RT {


    Stratified::Stratified(int numSamples, int numSampleSets) : ISampler(numSamples, numSampleSets) {
    }

    Stratified::~Stratified() = default;

    void Stratified::Generate() {
        std::vector<glm::vec2> samples;

        int side = static_cast<int>(std::sqrt((float)_numSamples));
        float div = 1.0f / (float)side;

        samples.reserve(side * side * _numSampleSets);

        for (int s = 0; s < _numSampleSets; ++s) {
            for (int i = 0; i < side; ++i) {
                for (int j = 0; j < side; ++j) {
                    samples.emplace_back(((float)j + glm::linearRand(0.0f, 1.0f)) * div, ((float)i + glm::linearRand(0.0f, 1.0f)) * div);
                }
            }
        }

        SetSamplePoints(samples);
    }

}
