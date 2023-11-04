#include <catch2/catch_test_macros.hpp>
#include "entt/entt.hpp"
#include "../../src/engine/world/WorldController.h"
#include "../../src/engine/Engine.h"
#include "../Tester.h"
#include "../../src/engine/world/components/CTransform.h"

namespace CEngine::EngineTest {
    static Engine engine;


    void shouldAddEntity() {
        IEntity *entity = engine.getWorldController().addEntity();
        REQUIRE(engine.getWorldController().hasEntity(entity->getUUID()) == true);
    }

    void shouldRemoveEntity() {
        IEntity *entity = engine.getWorldController().addEntity();
        std::string uuid = entity->getUUID();
        engine.getWorldController().removeEntity(uuid);
        REQUIRE(engine.getWorldController().hasEntity(uuid) == false);
    }


    void shouldAddComponent() {
        IEntity *entity = engine.getWorldController().addEntity();
        engine.getWorldController().addComponent<CTransform>(entity);
        IComponent *component = engine.getWorldController().getComponent<CTransform>(entity);

        REQUIRE(component != nullptr);
    }

    void shouldRemoveComponent() {
        IEntity *entity = engine.getWorldController().addEntity();
        engine.getWorldController().addComponent<CTransform>(entity);
        engine.getWorldController().removeComponent<CTransform>(entity);

        bool found = false;
        auto v = engine.getWorldController().getRegistry().view<CTransform>();
        for (auto ent: v) {
            if (ent == entity->getEntity()) {
                found = true;
            }
        }
        REQUIRE(engine.getWorldController().hasComponent<CTransform>(entity) == false);
        REQUIRE(found == false);
    }

    void shouldHaveComponent() {
        IEntity *entity = engine.getWorldController().addEntity();
        engine.getWorldController().addComponent<CTransform>(entity);

        bool found = false;
        auto v = engine.getWorldController().getRegistry().view<CTransform>();
        for (auto ent: v) {
            if (ent == entity->getEntity()) {
                found = true;
            }
        }
        REQUIRE(engine.getWorldController().hasComponent<CTransform>(entity) == true);
        REQUIRE(found == true);
    }


    Tester *createTester() {
        auto tester = new Tester("EngineTest");
        tester->registerTest("Should add entity", shouldAddEntity);
        tester->registerTest("Should remove entity", shouldRemoveEntity);
        tester->registerTest("Should add component", shouldAddComponent);
        tester->registerTest("Should remove component", shouldRemoveComponent);
        tester->registerTest("Should have component", shouldHaveComponent);
        return tester;
    }

}