#include "entitymanager.h"

EntityManager::EntityManager() {
    for(Entity i = 0; i < MAX_ENTITIES; i++) {
        availableIDs.push(i);
    }
}

Entity EntityManager::createEntity() {
    Entity newEntity = availableIDs.front();
    availableIDs.pop();
    ComponentSet newComponentSet;

    livingEntities[newEntity] = newComponentSet;

    return newEntity;
}

void EntityManager::destroyEntity(Entity id) {
    livingEntities.erase(id);
    availableIDs.push(id);
}

int EntityManager::getQtyEntities() {
    return livingEntities.size();
}

ComponentSet& EntityManager::getComponentSet(Entity id) {
    ComponentSet& set = livingEntities[id];

    return set;
}

std::vector<Entity> EntityManager::getEntities() {
    std::vector<Entity> entities;

    for(const auto& pair : livingEntities) {
        entities.push_back(pair.first);
    }

    return entities;
}