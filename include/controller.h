#ifndef STORAGE_CONTROLLER
    #define STORAGE_CONTROLLER
    #include "persister.h"
    #include "storage.h"
    #include <string>
    #include <vector>

    namespace controller
    {

        class StorageController {
            // we should define some mechanism to get the URI for read and write in disk.
            FilePersister persist;
            std::vector<Product> products;
            public:
                StorageController(FilePersister persist);
                ~StorageController();
                std::vector<Product> get_all();
                StoragedProduct get_storage(int id);
                void save_storages();
                std::vector<Product*> read_storages();
        };
        
    } // namespace controller

#endif