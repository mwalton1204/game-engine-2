#pragma once

#include "constants.h"
#include "components/basecomponent.h"

#include <unordered_map>
#include <array>
#include <vector>

#define SENTINEL_VALUE -1;

class ComponentManager {

    public:

        ComponentManager();
        template <typename T>
        void addComponent(Entity, Component, T);
        void removeComponent(Entity, Component);


    private:

        std::unordered_map<int, std::array<int, MAX_COMPONENTS>> indexMap;
        std::array<std::vector<BaseComponent>, MAX_COMPONENTS> componentData;
};

template <typename T>
void ComponentManager::addComponent(Entity eid, Component cid, T data){
    componentData[cid].push_back[data];
    indexMap[eid][cid] = componentData[cid].size() - 1;
}

void ComponentManager::removeComponent(Entity eid, Component cid){
    int indexToRemove = indexMap[eid][cid];

    componentData[cid].erase(componentData[cid].begin() + indexToRemove);

// entity is removed from components data vector
// iterate through all entities with this component
// if index is higher than indexToRemove, decrement by 1

    for(int i = 0; i < indexMap.size(); i++) {
        if(indexMap[i][cid] > indexToRemove) {
            int updatedIndex = indexMap[i][cid];
            indexMap[i][cid] = updatedIndex--;
        }
    }






    for (int i = 0; i < MAX_COMPONENTS; ++i) {
        if (indexMap[eid][i] > indexToRemove) {
            --indexMap[eid][i];
        }
    }
    
    indexMap[eid][cid] = SENTINEL_VALUE;
}