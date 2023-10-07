#include "ViewFactory.h"
#include <string>
#include "views/IView.h"
#include "views/TextView.h"
#include "views/SectionView.h"
#include "../../../DEFINITIONS.h"

namespace Catalyst::ui {
    IView *ui::ViewFactory::getViewByTag(const char *tag) {
        if (std::strcmp(tag, TEXT_VIEW) == 0) {
            return (IView *) new TextView;
        }
        if (std::strcmp(tag, SECTION_VIEW) == 0) {
            return (IView *) new SectionView;
        }
        return nullptr;
    }
}