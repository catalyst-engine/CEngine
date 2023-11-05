#include "Example.h"

CEngine::IElement *CEngine::Example::copy() {
    return new Example;
}
