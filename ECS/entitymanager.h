#pragma once

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

        std::unordered_map<Entity, ComponentSet> livingEntities;


};