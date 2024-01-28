#include "main.h"

int main() {
    EntityManager entityManager;
    std::vector<Entity> entities;
    int qtyEntities = entityManager.getQtyEntities();


/*
TEST ENTITY MANAGER
*/

//test creating entities and getting qty of living entities
    for(int i = 0; i < 5; i++) {
        Entity newEntity = entityManager.createEntity();

        qtyEntities = entityManager.getQtyEntities();
        std::cout << "Qty Entities: " << qtyEntities << std::endl << std::endl;
    }

//test getting living entity's id's
    entities = entityManager.getEntities();

    std::cout << "Living entities: ";
    for(Entity entity : entities) {
        std::cout << entity << ", ";
    }
    std::cout << std::endl;
    qtyEntities = entityManager.getQtyEntities();
    std::cout << "Qty Entities: " << qtyEntities << std::endl << std::endl;

//test getting and printing component sets

    std::bitset set = entityManager.getComponentSet(0);

    std::cout << "Entity: 0" << std::endl << "Component Set: ";

    for(int i = 0; i < set.size(); i++){
        std::cout << set[i];
    }
    std::cout << std::endl;

//test modifying component sets

    set.set(0);

    std::cout << "Entity: 0" << std::endl << "Component Set: ";

    for(int i = 0; i < set.size(); i++){
        std::cout << set[i];
    }
    std::cout << std::endl << std::endl;


//test destroying entities

    //destroy entity with id 2
    entityManager.destroyEntity(2);

    entities = entityManager.getEntities();
    std::cout << "Living entities: ";
    for(Entity entity : entities) {
        std::cout << entity << ", ";
    }
    std::cout << std::endl;
    qtyEntities = entityManager.getQtyEntities();
    std::cout << "Qty Entities: " << qtyEntities << std::endl << std::endl;

    //destroy entity with id 0
    entityManager.destroyEntity(0);

    entities = entityManager.getEntities();
    std::cout << "Living entities: ";
    for(Entity entity : entities) {
        std::cout << entity << ", ";
    }
    std::cout << std::endl;
    qtyEntities = entityManager.getQtyEntities();
    std::cout << "Qty Entities: " << qtyEntities << std::endl << std::endl;

    //destroy all living entities
    for(Entity entity : entities){
        entityManager.destroyEntity(entity);
        qtyEntities = entityManager.getQtyEntities();
        std::cout << "Qty Entities: " << qtyEntities << std::endl << std::endl;
    }

    entities = entityManager.getEntities();
    std::cout << "Living entities: ";
    for(Entity entity : entities) {
        std::cout << entity << ", ";
    }
    std::cout << std::endl;

    return 0;
}