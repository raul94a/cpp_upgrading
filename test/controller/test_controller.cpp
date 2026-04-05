
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

TEST(StorageControllerTest, FindStorageById) {
    FilePersister persister;
    StorageController cntr(persister);    
    StoragedProduct product(1, "Camiseta de rayas", 99.99, 1);
    Storage st(1, "Almacenes Llorones", "Martos");
    st.add_product(&product);
    cntr.add_storage(st);
    cntr.save_storages();
    Storage stt(20, "Almacenes Lloro", "Madrid");
    StoragedProduct productt(20, "Camiseta azul", 99, 1);
    stt.add_product(&product);
    stt.add_product(&productt);
    cntr.add_storage(stt);
    cntr.save_storages();

    StorageController cntr2(persister); 
    std::vector<Storage> loaded_storages = cntr2.read_storages();

    int storage_id = 1;

    Storage* storage = cntr2.get_storage(storage_id);
    EXPECT_EQ(storage->city,"Martos");

    int storage_idd = 20;

    Storage* storagee = cntr2.get_storage(storage_idd);
    EXPECT_EQ(storagee->city,"Madrid");

}

TEST(StorageControllerTest, CheckStorageWritingToLocalFile) {
    FilePersister persister;
    StorageController cntr(persister);    
    StoragedProduct product(1, "Camiseta de rayas", 99.99, 1);
    Storage st(1, "Almacenes Llorones", "Martos");
    st.add_product(&product);
    cntr.add_storage(st);
    cntr.save_storages();
    Storage stt(20, "Almacenes Lloro", "Madrid");
    StoragedProduct productt(20, "Camiseta azul", 99, 1);
    cntr.add_storage(stt);
    cntr.save_storages();
    Storage* madrid_storage = cntr.get_storage(20);


    madrid_storage->add_product(&productt);
    madrid_storage->add_product(&product);

    cntr.save_storages();


    StorageController cnt2(persister);

    std::vector<Storage> sts = cnt2.read_storages();

    Storage* st_last_ptr = (&sts[1]);

    EXPECT_EQ(st_last_ptr->products.size(),2);



}