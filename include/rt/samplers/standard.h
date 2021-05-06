
#ifndef RT_STANDARD_H
#define RT_STANDARD_H

#include <pch.h>
#include <rt/samplers/sampler.h>

namespace RT {

    class Standard : public ISampler {
        public:
            Standard(int numSamples, int numSampleSets);
            ~Standard();

            void Generate() override;
    };

}

#endif //RT_STANDARD_H
