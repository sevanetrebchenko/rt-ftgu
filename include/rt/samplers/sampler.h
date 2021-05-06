
#ifndef RT_SAMPLER_H
#define RT_SAMPLER_H

#include <pch.h>

namespace RT {

    class ISampler {
        public:
            ISampler(int numSamples, int numSampleSets);
            ~ISampler();

            virtual void Generate() = 0;

            void SetCosinePower(float power); // Used for hemisphere sampling.

            // Sampling.
            [[nodiscard]] const glm::vec2& SampleUnitSquare();
            [[nodiscard]] const glm::vec2& SampleUnitDisk();
            [[nodiscard]] const glm::vec3& SampleUnitHemisphere();

        protected:
            virtual void Shuffle(std::vector<glm::vec2>& samples);
            void SetSamplePoints(std::vector<glm::vec2>& samples);

            int _numSamples;
            int _numSampleSets;

        private:
            void InitShuffledIndices();
            [[nodiscard]] int GetNextSampleIndex();

            // Mapping functions.
            void MapToDisk();
            void MapToHemisphere();


            std::vector<glm::vec2> _squareSamples; // Samples in a unit square.
            std::vector<glm::vec2> _diskSamples;   // Samples in a unit circle.
            std::vector<glm::vec3> _hemisphereSamples;   // Samples in a unit hemisphere.
            float _cosinePower;
            std::vector<int> _indices;
            unsigned _sampleCount;
            int _indexJump;
    };

}

#endif //RT_SAMPLER_H
