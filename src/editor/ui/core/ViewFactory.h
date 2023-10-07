#pragma once

#ifndef CATALYST_VIEWFACTORY_H
#define CATALYST_VIEWFACTORY_H

#include <string>

namespace Catalyst::ui {
    class IView;
    class TextView;
    class SectionView;
    class ViewFactory {
    public:
        static IView *getViewByTag(const char *tag);
    };
}
#endif
