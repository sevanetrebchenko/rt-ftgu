
#include <rt/samplers/multi_stratified.h>
#include <rt/utilities/random.h>

namespace RT {

    MultiStratified::MultiStratified(int numSamples, int numSampleSets) : ISampler(numSamples, numSampleSets) {

    }

    MultiStratified::~MultiStratified() = default;

    void MultiStratified::Shuffle(std::vector<glm::vec2>& samples) {
        int n = static_cast<int>(std::sqrt((float)_numSamples)); // Must be perfect root.

        // Shuffle x-coordinates.
        for (int set = 0; set < _numSampleSets; ++set) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int k = Random(j, n - 1);
                    std::swap(samples[i * n + j + set * _numSamples].x, samples[i * n + k + set * _numSamples].x);
                }
            }
        }

        // Shuffle y-coordinates.
        for (int set = 0; set < _numSampleSets; ++set) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int k = Random(j, n - 1);
                    std::swap(samples[j * n + i + set * _numSamples].y, samples[k * n + i + set * _numSamples].y);
                }
            }
        }
    }

    void MultiStratified::Generate() {
        std::vector<glm::vec2> samples;
        samples.reserve(_numSamples * _numSampleSets);

        int n = static_cast<int>(std::sqrt((float)_numSamples)); // Must be perfect root.
        float subcellWidth = 1.0f / (float)_numSamples;

        // Construct initial array.
        for (int i = 0; i < _numSamples * _numSampleSets; ++i) {
            samples.emplace_back(0.0f, 0.0f);
        }

        // Distribute initial stratified points.
        for (int set = 0; set < _numSampleSets; ++set) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int index = i * n + j + set * _numSamples;

                    samples[index].x = (float)(i * n + j) * subcellWidth + glm::linearRand(0.0f, subcellWidth);
                    samples[index].y = (float)(j * n + i) * subcellWidth + glm::linearRand(0.0f, subcellWidth);
                }
            }
        }

        Shuffle(samples);
        SetSamplePoints(samples);
    }

}


