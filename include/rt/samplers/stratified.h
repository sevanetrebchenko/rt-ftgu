
#ifndef RT_STRATIFIED_H
#define RT_STRATIFIED_H

#include <rt/samplers/sampler.h>

namespace RT {

    class Stratified : public ISampler {
        public:
            explicit Stratified(int numSamples = 36, int numSampleSets = 83);
            ~Stratified() override;

            void Generate() override;
    };

}

#endif //RT_STRATIFIED_H
