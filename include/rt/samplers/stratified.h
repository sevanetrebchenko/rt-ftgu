
#ifndef RT_STRATIFIED_H
#define RT_STRATIFIED_H

#include <rt/samplers/sampler.h>

namespace RT {

    class Stratified : public ISampler {
        public:
            Stratified(int numSamples, int numSampleSets);
            ~Stratified();

            void Generate() override;
    };

}

#endif //RT_STRATIFIED_H
