
#ifndef RT_N_ROOKS_H
#define RT_N_ROOKS_H

#include <rt/samplers/sampler.h>

namespace RT {

    class NRooks : public ISampler {
        public:
            explicit NRooks(int numSamples = 36, int numSampleSets = 83);
            ~NRooks() override;

            void Generate() override;
    };

}

#endif //RT_N_ROOKS_H
