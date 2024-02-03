#pragma once

#include "constants.h"
#include "components/basecomponent.h"

#include <unordered_map>
#include <array>
#include <vector>

#define SENTINEL_INDEX -1

class ComponentManager {

    public:

        template <typename T>
        void addComponent(Entity, Component, T);
        template <typename T>
        void getComponentData(Entity, Component, T&);
        template<typename T>
        void updateData(Entity, Component, const T&);
        void removeComponent(Entity, Component);
        void entityDestroyed(Entity);

    private:

        //array of vectors for each component that hold entity component data
        std::array<std::vector<BaseComponent>, MAX_COMPONENTS> componentData;
        // map with each entity keys and array values that store indices into each component's data vector
        std::unordered_map<int, std::array<int, MAX_COMPONENTS>> indexMap;
};

template <typename T>
void ComponentManager::addComponent(Entity entityID, Component componentID, T newData) {

componentData[componentID].push_back(newData);

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
void ComponentManager::getComponentData(Entity entityID, Component componentID, T& emptyData) {
//TODO: verify that entity has component
    int indexToGet = indexMap[entityID][componentID];
    emptyData = componentData[componentID][indexToGet];
}

template <typename T>
void ComponentManager::updateData(Entity entityID, Component componentID, const T& newData) {
//TODO: verify
    int indexToChange = indexMap[entityID][componentID];
    componentData[componentID][indexToChange] = newData;
}