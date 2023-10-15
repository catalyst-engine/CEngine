#pragma once
#ifndef CATALYST_ESECTION_H
#define CATALYST_ESECTION_H


#include "imgui.h"
#include "IElement.h"
#include "AbstractTitledElement.h"

namespace Catalyst {
    class ESection : public AbstractTitledElement {
    private:
        ImVec2 size = ImVec2(10, 10);
        ImGuiWindowFlags flags = 0;
        bool noTitleBar = false;
        bool noScrollbar = false;
        bool menuBar = false;
        bool noMove = false;
        bool noResize = false;
        bool noCollapse = false;
        bool noNav = false;
        bool noBackground = false;
        bool noBringToFrontOnFocus = false;
        bool noDocking = false;
        bool unsavedDocument = false;
        void loadFlags();
    public:
        const ImVec2 &getSize() const;

        void setSize1(const ImVec2 &size);

        bool isNoTitleBar() const;

        void setNoTitleBar(bool noTitleBar);

        bool isNoScrollbar() const;

        void setNoScrollbar(bool noScrollbar);

        bool isMenuBar() const;

        void setMenuBar(bool menuBar);

        bool isNoMove() const;

        void setNoMove(bool noMove);

        bool isNoResize() const;

        void setNoResize(bool noResize);

        bool isNoCollapse() const;

        void setNoCollapse(bool noCollapse);

        bool isNoNav() const;

        void setNoNav(bool noNav);

        bool isNoBackground() const;

        void setNoBackground(bool noBackground);

        bool isNoBringToFrontOnFocus() const;

        void setNoBringToFrontOnFocus(bool noBringToFrontOnFocus);

        bool isNoDocking() const;

        void setNoDocking(bool noDocking);

        bool isUnsavedDocument() const;

        void setUnsavedDocument(bool unsavedDocument);

        void setSize(float x, float y) {
            size.x = x;
            size.y = y;
        }

        void render() override;

        IElement *copy() override;

        void collectAttributes(pugi::xml_node node) override;
    };
}

#endif //CATALYST_ESECTION_H












