#pragma once

#ifndef CATALYST_TEXTCONTROLLER_H
#define CATALYST_TEXTCONTROLLER_H

#include "AbstractController.h"

namespace Catalyst::ui {
    class TextController : public AbstractController {
    public:
        void update() override;
    };
}

#endif
