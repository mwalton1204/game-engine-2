#include "main.h"

int main() {
    EntityManager entityManager;

    for(int i = 0; i < 5; i++) {
        Entity newEntity = entityManager.createEntity();

        int qtyEntities = entityManager.getQtyEntities();
        std::cout << "quantity of entities: " << qtyEntities << std::endl;
    }

    return 0;
}