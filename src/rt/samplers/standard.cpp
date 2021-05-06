
#include <rt/samplers/standard.h>

namespace RT {

    Standard::Standard(int numSamples, int numSampleSets) : ISampler(numSamples, numSampleSets) {
    }

    Standard::~Standard() = default;

    void Standard::Generate() {
        std::vector<glm::vec2> samples;
        int n = static_cast<int>(std::sqrt((float)_numSamples)); // Must be perfect root.

        samples.reserve(n * n * _numSampleSets);

        for (int set = 0; set < _numSampleSets; ++set) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Regular sampler places one sample point at the middle of each pixel.
                    samples.emplace_back(((float)j + 0.5f) / (float)n, ((float)i + 0.5f) / (float)n);
                }
            }
        }

        SetSamplePoints(samples);
    }

}
