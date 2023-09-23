//
// Created by russi on 9/23/2023.
//

#ifndef CATALYST_ENGINE_UICOMPONENT_H
#define CATALYST_ENGINE_UICOMPONENT_H

#include "../util/LinkedList.h"

namespace ui {
    class AbstractUI {
    public:
        virtual void Render() {}
    };
    namespace document {
        util::basic::LinkedList<ui::AbstractUI> elements;

        template<typename T>
        T AddElement() {
            auto newInstance = T();
            elements.Push(&newInstance);
            return newInstance;
        }

        void Render() {
            size_t length = elements.Length();
            for (int i = 0; i < length; i++) {
                AbstractUI *element = elements.Get(i);
                element->Render();
            }
        }
    }
}
#endif //CATALYST_ENGINE_UICOMPONENT_H
