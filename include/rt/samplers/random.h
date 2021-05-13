
#ifndef RT_RANDOM_H
#define RT_RANDOM_H

#include <rt/samplers/sampler.h>

namespace RT {

    class Random : public ISampler {
        public:
            explicit Random(int numSamples = 36, int numSampleSets = 83);
            ~Random() override;

            void Generate() override;
    };

}

#endif //RT_RANDOM_H
