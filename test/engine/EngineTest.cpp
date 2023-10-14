#include <catch2/catch_test_macros.hpp>
#include "entt/entt.hpp"
#include "../../src/engine/components/CMetadata.h"
#include "../../src/engine/world/World.h"
#include "../../src/engine/Engine.h"
#include "../Tester.h"

namespace Catalyst::EngineTest{

    class Comp : public Catalyst::engine::IComponent {
    public:
        explicit Comp(entt::entity ent) : IComponent(ent) {}
    };


    void shouldAddEntity() {
        engine::World *world = Engine::getWorld();
        engine::WorldRegistry *reg = Engine::getRegistry();
        entt::entity entity = world->addEntity();
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
        engine::World *world = Engine::getWorld();
        engine::WorldRegistry *reg = Engine::getRegistry();
        entt::entity entity = world->addEntity();

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
        engine::World *world = Engine::getWorld();
        engine::WorldRegistry *reg = Engine::getRegistry();
        entt::entity entity = world->addEntity();

        world->addComponent<Comp>(entity);

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
        engine::World *world = Engine::getWorld();
        engine::WorldRegistry *reg = Engine::getRegistry();
        entt::entity entity = world->addEntity();

        world->addComponent<Comp>(entity);
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
        engine::World *world = Engine::getWorld();
        engine::WorldRegistry *reg = Engine::getRegistry();
        entt::entity entity = world->addEntity();
        world->addComponent<Comp>(entity);
        REQUIRE(reg->hasComponent<Comp>(entity) == true);
    }

    void shouldHaveMetadata() {
        engine::World *world = Engine::getWorld();
        engine::WorldRegistry *reg = Engine::getRegistry();
        entt::entity entity = world->addEntity();
        REQUIRE(reg->getEntityMetadata(entity) != nullptr);
    }


    Tester *createTester() {
        auto tester = new Tester("EngineTest");
        tester->registerTest("Should add entity", shouldAddEntity);
        tester->registerTest("Should remove entity", shouldRemoveEntity);
        tester->registerTest("Should add component", shouldAddComponent);
        tester->registerTest("Should remove component", shouldRemoveComponent);
        tester->registerTest("Should have component", shouldHaveComponent);
        tester->registerTest("Should have metadata", shouldHaveMetadata);
        return tester;
    }


}