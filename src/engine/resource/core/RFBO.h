#ifndef CATALYST_RFBO_H
#define CATALYST_RFBO_H

#include <vector>
#include "IResource.h"
#include "../dto/FBOTextureDTO.h"

namespace CEngine {

    class RFBO : public IResource {
    private:
        int width = 640;
        int height = 480;
        unsigned int fbo;
        unsigned int rbo;
        unsigned int depthSampler;
        std::vector<unsigned int> colors;
        std::vector<unsigned int> attachments;
        std::vector<FBOTextureDTO *> colorsMetadata;
    public:
        explicit RFBO() : IResource(ResourceType::FBO) {}

        ~RFBO() override;

        void startMapping(bool noClearing);

        void stopMapping();

        RFBO *depthTexture();

        RFBO *depthTest();

        RFBO *texture(FBOTextureDTO *obj);

        void use();

        void clear();
    };

}

#endif
