#ifndef CATALYST_INPUTSYSTEM_H
#define CATALYST_INPUTSYSTEM_H

#include "../ISystem.h"

namespace CEngine {

    class InputSystem : public ISystem {
    public:
        void run() override;
    };

}

#endif
