#ifndef CATALYST_EBUTTON_H
#define CATALYST_EBUTTON_H

#include "IElement.h"

namespace Catalyst {

    class EButton : public IElement {
    private:
        bool clicked = false;
        std::string title;
    public:
        const std::string &getTitle() const;

        void setTitle(std::string t);

    public:
        bool isClicked() const;

        void render() override;
    };

}

#endif
