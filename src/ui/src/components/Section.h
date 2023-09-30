#ifndef CATALYST_SECTION_H
#define CATALYST_SECTION_H


#include "imgui.h"
#include "Component.h"
namespace Catalyst::ui {
    class Section : public Component {
    public:
        void render() override;
    };
}

#endif //CATALYST_SECTION_H
