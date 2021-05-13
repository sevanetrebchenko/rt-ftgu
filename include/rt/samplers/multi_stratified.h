
#ifndef RT_MULTI_STRATIFIED_H
#define RT_MULTI_STRATIFIED_H

#include <rt/samplers/sampler.h>

namespace RT {

    class MultiStratified : public ISampler {
        public:
            explicit MultiStratified(int numSamples = 36, int numSampleSets = 83);
            ~MultiStratified() override;

        private:
            void Shuffle(std::vector<glm::vec2>& samples) override;
            void Generate() override;
    };

}

#endif //RT_MULTI_STRATIFIED_H
