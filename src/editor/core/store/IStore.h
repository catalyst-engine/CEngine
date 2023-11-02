#ifndef CATALYST_ISTORE_H
#define CATALYST_ISTORE_H


#include "../../../engine/event/EventController.h"
#include "../../../engine/util/UUID.h"

namespace Catalyst {

    template<class STORE, class DATA>
    class IStore {
    private:
        static std::string storeId;
        static STORE instance;
        DATA *data = new DATA;
    public:
        static DATA *getData() {
            return instance.data;
        }

        static std::string getStoreId() {
            if(storeId.empty()){
                storeId = UUID::v4();
            }
            return storeId;
        }

        static void updateData(DATA *temp) {
            if (temp != instance.data) {
                delete instance.data;
            }
            instance.data = temp;
            EventController::get()->triggerEvent(getStoreId());
        }

        static void clear() {
            instance.data = new DATA;
        }
    };

    template<class STORE, class DATA>
    STORE IStore<STORE, DATA>::instance;

    template<class STORE, class DATA>
    std::string IStore<STORE, DATA>::storeId;
}


#endif
