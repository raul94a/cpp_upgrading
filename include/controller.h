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
            std::vector<Storage> storages;
            public:
                StorageController(FilePersister persist);
                ~StorageController();
                std::vector<Storage> get_all();
                Storage* get_storage(int id);
                void add_storage(Storage pr);
                void save_storages();
                std::vector<Storage> read_storages();
        };
        
    } // namespace controller

#endif