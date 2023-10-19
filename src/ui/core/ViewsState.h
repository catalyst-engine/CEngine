#ifndef CATALYST_VIEWSSTATE_H
#define CATALYST_VIEWSSTATE_H


#include "../../util/structures/List.h"
#include "pugixml.hpp"
#include "../../util/debug/ILoggable.h"
#include <string>

namespace Catalyst {
    template<typename K, typename V>
    class Map;

    class IView;

    class IElement;

    class ViewsState : public ILoggable {
    private:
        List<IView> views;
    public:
        static Map<std::string, IView *> registeredViews;

        List<IView> *getViews();

        IView *addView(const char *tag);
    };
}


#endif
