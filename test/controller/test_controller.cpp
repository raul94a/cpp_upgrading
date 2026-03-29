
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
    StorageController cntr = StorageController(FilePersister());
    StoragedProduct product = StoragedProduct(1,"Camiseta de rayas", 99.99, 1);
    Storage st = Storage(1,"Almacenes Llorones", "Martos");
    st.add_product(&product);
    std::vector<Storage> storages = cntr.get_all();
    cntr.add_storage(st);
    std::cout << "Number of storages: " << cntr.get_all().size() << std::endl;
    cntr.save_storages();
    cntr.get_all().clear();
    EXPECT_NE(cntr.read_storages().size(),2);
    EXPECT_EQ(cntr.read_storages().size(),1);

}