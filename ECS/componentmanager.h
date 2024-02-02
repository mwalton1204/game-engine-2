#pragma once

#include "constants.h"
#include "components/basecomponent.h"

#include <unordered_map>
#include <array>
#include <vector>

#define SENTINEL_INDEX -1;

class ComponentManager {

    public:

        ComponentManager();
        template <typename T>
        void addComponent(Entity, Component, T);
        void removeComponent(Entity, Component);
        //entityDestroyed
        template <typename T>
        void getComponentData(Entity, Component, T&);
        //updateData


    private:

//array of vectors for each component that hold entity component data
        std::array<std::vector<BaseComponent>, MAX_COMPONENTS> componentData;
// map with each entity keys and array values that store indices into each component's data vector
        std::unordered_map<int, std::array<int, MAX_COMPONENTS>> indexMap;
};

template <typename T>
void ComponentManager::addComponent(Entity entityID, Component componentID, T data){

componentData[componentID].push_back[data];

//create a new array filled with sentinel values if one does not already exist for this entity
    if(indexMap.find(entityID) == indexMap.end()) {
        std::array<int, MAX_COMPONENTS> newArray;
        newArray.fill(SENTINEL_INDEX);
        newArray[componentID] = componentData[componentID].size() - 1;
        indexMap[entityID] = newArray;
    } else {
//TODO: verify that entity does not have component
        indexMap[entityID][componentID] = componentData[componentID].size() - 1;
    }
}

template <typename T>
void getComponentData(Entity entityID, Component componentID, T& emptyData) {
//TODO: verify that entity has component
    int indexToGet = indexMap[entityID][componentID];
    emptyData = componentData[componentID][indexToGet];
}

void ComponentManager::removeComponent(Entity entityID, Component componentID){
    auto& entityIndices = indexMap[entityID];

//TODO: verify that entity has component

    int indexToRemove = indexMap[entityID][componentID];
    componentData[componentID].erase(componentData[componentID].begin() + indexToRemove);

// decrement index values that were higher than indexToRemove because vector resizes dynamically
    for(int i = 0; i < entityIndices.size(); i++) {
        if(entityIndices[i] > indexToRemove) {
            entityIndices[i]--;
        }
    }
    
//replace the index for this component with sentinel value    
    indexMap[entityID][componentID] = SENTINEL_INDEX;
}