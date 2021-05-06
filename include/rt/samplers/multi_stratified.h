
#ifndef RT_MULTI_STRATIFIED_H
#define RT_MULTI_STRATIFIED_H

#include <rt/samplers/sampler.h>

namespace RT {

    class MultiStratified : public ISampler {
        public:
            MultiStratified(int numSamples, int numSampleSets);
            ~MultiStratified();

        private:
            void Shuffle(std::vector<glm::vec2>& samples) override;
            void Generate() override;
    };

}

#endif //RT_MULTI_STRATIFIED_H
