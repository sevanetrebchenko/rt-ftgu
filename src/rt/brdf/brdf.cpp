
#include <rt/brdf/brdf.h>

namespace RT {

    IBRDF::IBRDF(ISampler* sampler) : _sampler(sampler) {
        _sampler->Generate();
    }

    IBRDF::~IBRDF() {
        delete _sampler;
    }

}
