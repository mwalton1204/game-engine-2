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

void EntityManager::destroyEntity(Entity id) {}

int EntityManager::getQtyEntities() {
    return livingEntities.size();
}