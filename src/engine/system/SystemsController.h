#ifndef CATALYST_SYSTEMSCONTROLLER_H
#define CATALYST_SYSTEMSCONTROLLER_H

#include "ISystem.h"
#include "structures/List.h"

namespace CEngine {

    class SystemsController {
    private:
        List<ISystem> systems;

        void registerSystem(ISystem system);

    public:
        template<class T>
        void createSystem(){

        }

        void update();
    };

}

#endif
