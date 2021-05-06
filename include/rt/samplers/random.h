
#ifndef RT_RANDOM_H
#define RT_RANDOM_H

#include <rt/samplers/sampler.h>

namespace RT {

    class Random : public ISampler {
        public:
            Random(int numSamples, int numSampleSets);
            ~Random();

            void Generate() override;
    };

}

#endif //RT_RANDOM_H
