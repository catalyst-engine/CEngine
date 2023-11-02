#include "AbstractSimpleElement.h"

namespace Catalyst {
    void AbstractSimpleElement::setText(std::string textV) {
        text = std::move(textV);
    }

    const std::string &AbstractSimpleElement::getText() const {
        return text;
    }
}