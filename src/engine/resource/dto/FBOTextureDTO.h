#ifndef CATALYST_FBOTEXTUREDTO_H
#define CATALYST_FBOTEXTUREDTO_H

namespace CEngine {
    struct FBOTextureDTO {
        int w;
        int h;
        int attachment;
        int precision;
        int format;
        int type;
        bool linear;
        bool repeat;
    };
}
#endif
