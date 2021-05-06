
#ifndef RT_N_ROOKS_H
#define RT_N_ROOKS_H

#include <rt/samplers/sampler.h>

namespace RT {

    class NRooks : public ISampler {
        public:
            NRooks(int numSamples, int numSampleSets);
            ~NRooks();

            void Generate() override;
    };

}

#endif //RT_N_ROOKS_H
