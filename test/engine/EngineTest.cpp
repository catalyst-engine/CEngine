#include <catch2/catch_test_macros.hpp>
#include "entt/entt.hpp"
#include "../../src/engine/world/WorldController.h"
#include "../../src/engine/Engine.h"
#include "../Tester.h"
#include "../../src/engine/world/components/IComponent.h"
#include "../../src/engine/world/IEntity.h"

namespace CEngine::EngineTest {
    static Engine engine;

    class Comp : public IComponent {
    public:
        explicit Comp(IEntity *ent) : IComponent(ent) {}
    };


    void shouldAddEntity() {
        IEntity *entity = engine.getWorldController().addEntity();
        bool found = false;
        auto v = reg->getRegistry()->view<engine::CMetadata>();
        for (auto ent: v) {
            if (ent == entity) {
                found = true;
            }
        }
        REQUIRE(found == true);
    }

    void shouldRemoveEntity() {
        IEntity *entity = engine.getWorldController().addEntity();

        world->removeEntity(entity);

        bool found = false;
        auto v = reg->getRegistry()->view<engine::CMetadata>();
        for (auto ent: v) {
            if (ent == entity) {
                found = true;
            }
        }
        REQUIRE(found == false);
    }


    void shouldAddComponent() {
        IEntity *entity = engine.getWorldController().addEntity();

        engine.getWorldController().addComponent<Comp>(entity);
        bool found = false;
        auto v = reg->getRegistry()->view<Comp>();
        for (auto ent: v) {
            if (ent == entity) {
                found = true;
            }
        }
        REQUIRE(found == true);
    }

    void shouldRemoveComponent() {
        IEntity *entity = engine.getWorldController().addEntity();

        engine.getWorldController().addComponent<Comp>(entity);
        world->removeComponent<Comp>(entity);

        bool found = false;
        auto v = reg->getRegistry()->view<Comp>();
        for (auto ent: v) {
            if (ent == entity) {
                found = true;
            }
        }
        REQUIRE(found == false);
    }

    void shouldHaveComponent() {
        IEntity *entity = engine.getWorldController().addEntity();

        engine.getWorldController().addComponent<Comp>(entity);
        REQUIRE(engine.getWorldController().hasComponent<Comp>(entity) == true);
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