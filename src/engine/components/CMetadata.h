#ifndef CATALYST_CMETADATA_H
#define CATALYST_CMETADATA_H

#include "UUID.h"
#include "IComponent.h"
#include "imgui.h"

namespace Catalyst::engine {

    class CMetadata : public IComponent {
    private:
        std::string name = "New entity";
        ImVec4 color = ImVec4{0, 0, 0, 1};
        std::string entityUUID = Catalyst::UUID::v4();
    public:
        explicit CMetadata(entt::entity ent) : IComponent(ent) {}

        std::string getName();

        ImVec4 getColor();

        std::string getEntityUUID();

        void setName(std::string newName);

        void setColor(float r, float g, float b);
    };
}

#endif //CATALYST_CMETADATA_H
