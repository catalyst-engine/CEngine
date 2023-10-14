#ifndef CATALYST_WORLDREGISTRY_H
#define CATALYST_WORLDREGISTRY_H

#include "entt/entt.hpp"
#include "../../util/debug/ILoggable.h"

namespace Catalyst::engine {
    class CMetadata;

    /**
     * For querying data and storing registry
     * */
    class WorldRegistry : public ILoggable {
    private:
        entt::registry worldReg;
    public:

        entt::registry *getRegistry();

        CMetadata *getEntityMetadata(entt::entity ent);

        template<class T>
        T *getComponent(entt::entity ent) {
            return worldReg.get<T>(ent);
        }

        template<class T>
        bool hasComponent(entt::entity ent) {
            return worldReg.all_of<T>(ent);
        }
    };

}

#endif
