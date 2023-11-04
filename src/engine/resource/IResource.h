#ifndef CATALYST_IRESOURCE_H
#define CATALYST_IRESOURCE_H

#include <string>

namespace CEngine {

    class IResource {
    public:
        virtual bool isDeletable(){
            return true;
        }

        virtual std::string getId(){
            return "";
        }
    };

}
#endif
