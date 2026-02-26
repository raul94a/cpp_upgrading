#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>
#include "product.h" // Se encuentra automáticamente por herencia de Logic
#include "storage.h"
int EXPECTED_ID = 1;
std::string EXPECTED_NAME = "pr1";
double EXPECTED_PRICE = 10.0;
int EXPECTED_QUANTITY = 10;

StoragedProduct* _create_product(int id, int qty){
   
    StoragedProduct* pr = new StoragedProduct(
                id,
                EXPECTED_NAME,
                EXPECTED_PRICE,
                qty
    );
    return pr;
}

Storage _create_storage(int id){
    Storage st = Storage(id, "nombre", "city");
    return st;
}
TEST(Storage, SetArguments) {
    Storage st = _create_storage(20);
    EXPECT_EQ(st.id,20);
    EXPECT_EQ(st.name,"nombre");
    EXPECT_EQ(0, st.products.size());
}


TEST(Storage,Sell) {
   Storage st = _create_storage(20);
   StoragedProduct* pr = _create_product(1,20);

   st.add_product(pr);
  // delete pr;
   EXPECT_EQ(st.products.size(), 1);

   EXPECT_FALSE(st.sell(99,9));
   EXPECT_FALSE(st.sell(1,21));
   EXPECT_TRUE(st.sell(1,19));
   int searchId = 1;
   auto storageProductPtr = std::find_if(st.products.begin(),st.products.end(), [searchId](const auto& pr){
     return pr.id == 1;
   });
   EXPECT_NE(storageProductPtr,st.products.end());
   EXPECT_EQ(storageProductPtr->quantity,1);
   delete pr;
}



