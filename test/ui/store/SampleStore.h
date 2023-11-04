#ifndef CATALYST_SAMPLESTORE_H
#define CATALYST_SAMPLESTORE_H

#include "../../../src/editor/core/store/IStore.h"
#include "SampleData.h"

namespace CEngine {

    class SampleStore : public IStore<SampleStore, SampleData> {

    };
}

#endif
