#pragma once

#include "../util/LinkedList.h"

namespace UI {
    class AbstractUI {
    private:
        Util::Basic::LinkedList<UI::AbstractUI> children;
    protected:
        void renderChildren() {
            children.iterate();
            while (children.hasNext()) {
                UI::AbstractUI *next = children.next();
                next->render();
            }
        }

    public:
        virtual void render() {}

        template<typename T>
        T* addChild() {
            auto newInstance = new T();
            children.push(newInstance);
            return newInstance;
        }

        void removeChild(AbstractUI *child) {
            children.remove(child);
        }
    };
    namespace Document {
        Util::Basic::LinkedList<UI::AbstractUI> elements;

        template<typename T>
        T* addElement() {
            auto newInstance = new T();
            elements.push(newInstance);
            return newInstance;
        }

        void render() {
            elements.iterate();
            while (elements.hasNext()) {
                AbstractUI *next = elements.next();
                next->render();
            }
        }
    }
}
