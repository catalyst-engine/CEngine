#ifndef CATALYST_ISTORE_H
#define CATALYST_ISTORE_H

namespace Catalyst {

    template<class T>
    class IStore {
    private:
        static IStore<T> instance;
        T *data = new T;
    public:
        static T *getData() {
            return instance.getData();
        }

        static void updateData(T *temp) {
            if (temp != instance.data) {
                delete instance.data;
            }
            instance.data = temp;
        }
    };

}

#endif
