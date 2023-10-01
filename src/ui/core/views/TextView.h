#pragma once
#ifndef CATALYST_TEXTVIEW_H
#define CATALYST_TEXTVIEW_H

#include "AbstractView.h"

namespace Catalyst::ui {
    class TextView : public AbstractView {
    public:
        void render() override;
    };
}

#endif //CATALYST_TEXTVIEW_H
