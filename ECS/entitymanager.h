#pragma once

#include <queue>
#include <unordered_map>

#include "constants.h"

class EntityManager {

    public:

        EntityManager();
        Entity createEntity();
        void destroyEntity(Entity);
        int getQtyEntities();
        ComponentSet& getComponentSet(Entity);


    private:

        std::queue<Entity> availableIDs;
        std::unordered_map<Entity, ComponentSet> livingEntities;
};