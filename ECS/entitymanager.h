#pragma once

#include <queue>
#include <unordered_map>

#include "constants.h"

class EntityManager {

    public:

        EntityManager(); //initialize queue of available entity id's
        Entity createEntity(); //get available id, pop from available, create new ComponentSet, store in livingEntities, return entity id
        void destroyEntity(Entity); //erase from living entities, return id to available
        int getQtyEntities(); //return livingEntities.size()
        ComponentSet& getComponentSet(Entity); //return reference to livingEntities[id]


    private:

        std::queue<Entity> availableIDs; //unused id's
        std::unordered_map<Entity, ComponentSet> livingEntities; //living entities and their component sets
};