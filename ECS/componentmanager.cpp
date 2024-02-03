#include "componentmanager.h"

void ComponentManager::removeComponent(Entity entityID, Component componentID) {
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

void ComponentManager::entityDestroyed(Entity entityID) {
//TODO: verify

    for(int componentID = 0; componentID < MAX_COMPONENTS; componentID++) {
        if(indexMap[entityID][componentID] != SENTINEL_INDEX) {
            removeComponent(entityID, componentID);
        }
    }
}