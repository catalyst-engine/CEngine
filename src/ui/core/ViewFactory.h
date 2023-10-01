#pragma once

#ifndef CATALYST_VIEWFACTORY_H
#define CATALYST_VIEWFACTORY_H

#include <string>
#include "xercesc/util/XMLString.hpp"

namespace Catalyst::ui {
    class AbstractView;
    class TextView;
    class SectionView;
    class ViewFactory {
    public:
        static AbstractView *getViewByTag(const char *tag);
    };
}
#endif
