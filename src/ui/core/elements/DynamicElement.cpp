#include "DynamicElement.h"

namespace CEngine {
    void DynamicElement::render() {
        renderElements(element);
    }

    DynamicElement::DynamicElement(IElement *element, void (*renderElements)(IElement*element)) {
        this->element = element;
        DynamicElement::renderElements = renderElements;
    }
}