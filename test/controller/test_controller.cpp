
#include <gtest/gtest.h>
#include <string>
#include "controller.h"

using namespace controller;

// Flaky
TEST(StorageControllerTest, ReadFromLocalFile) {
    StorageController cntr = StorageController(FilePersister());
    std::vector<Storage> storages = cntr.read_storages();
    std::cout << "Number of storages: " << storages.size() << std::endl;
    EXPECT_EQ(storages.size(), 0);
}

TEST(StorageControllerTest, WriteToLocalFile) {
    FilePersister persister;
    StorageController cntr(persister);
    
    StoragedProduct product(1, "Camiseta de rayas", 99.99, 1);
    Storage st(1, "Almacenes Llorones", "Martos");
    st.add_product(&product);
    
    cntr.add_storage(st);
    ASSERT_EQ(cntr.get_all().size(), 1); // Verificación previa
    cntr.save_storages();

    
    StorageController cntr2(persister); 
    std::vector<Storage> loaded_storages = cntr2.read_storages();

    EXPECT_EQ(loaded_storages.size(), 1);
    
    if (!loaded_storages.empty()) {
        EXPECT_EQ(loaded_storages[0].name, "Almacenes Llorones");
        EXPECT_EQ(loaded_storages[0].city, "Martos");
        
        
        EXPECT_EQ(loaded_storages[0].products.size(), 1);
    }

}