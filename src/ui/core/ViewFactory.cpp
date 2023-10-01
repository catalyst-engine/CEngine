#include "ViewFactory.h"
#include <string>
#include "views/AbstractView.h"
#include "views/TextView.h"
#include "views/SectionView.h"

namespace Catalyst::ui {
    AbstractView *ui::ViewFactory::getViewByTag(const char *tag) {
        if (std::strcmp(tag, "TextView") == 0) {
            return (AbstractView *) new TextView;
        }
        if (std::strcmp(tag, "SectionView") == 0) {
            return (AbstractView *) new SectionView;
        }
        return nullptr;
    }
}