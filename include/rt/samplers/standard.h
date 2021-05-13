
#ifndef RT_STANDARD_H
#define RT_STANDARD_H

#include <pch.h>
#include <rt/samplers/sampler.h>

namespace RT {

    class Standard : public ISampler {
        public:
            explicit Standard(int numSamples = 36, int numSampleSets = 83);
            ~Standard() override;

            void Generate() override;
    };

}

#endif //RT_STANDARD_H
