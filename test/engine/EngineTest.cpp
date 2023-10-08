#include <catch2/catch_test_macros.hpp>
#include "entt/entt.hpp"
#include "../../src/engine/components/CMetadata.h"
#include "../../src/engine/world/World.h"
#include "../../src/engine/Engine.h"

using namespace Catalyst;

class Comp : public Catalyst::engine::IComponent {
public:
    explicit Comp(entt::entity ent) : IComponent(ent) {}
};

TEST_CASE("Should add entity", "[add-entity]") {
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


TEST_CASE("Should remove entity", "[remove-entity]") {
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

TEST_CASE("Should add component", "[add-component]") {
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
TEST_CASE("Should remove component", "[remove-component]") {
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

TEST_CASE("Should have component", "[has-component]") {
    engine::World *world = Engine::getWorld();
    engine::WorldRegistry *reg = Engine::getRegistry();
    entt::entity entity = world->addEntity();
    world->addComponent<Comp>(entity);
    REQUIRE(reg->hasComponent<Comp>(entity) == true);
}

TEST_CASE("Should have metadata", "[has-metadata]") {
    engine::World *world = Engine::getWorld();
    engine::WorldRegistry *reg = Engine::getRegistry();
    entt::entity entity = world->addEntity();
    REQUIRE(reg->getEntityMetadata(entity) != nullptr);
}
