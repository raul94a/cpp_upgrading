#include <gtest/gtest.h>
#include <string>
#include "product.h" // Se encuentra automáticamente por herencia de Logic


#pragma once
inline constexpr int EXPECTED_ID = 1;
inline std::string EXPECTED_NAME = "pr1";
inline constexpr double EXPECTED_PRICE = 10.0;
inline constexpr int EXPECTED_QUANTITY = 10;

StoragedProduct* _create_product(){
   
    StoragedProduct* pr = new StoragedProduct(
                EXPECTED_ID,
                EXPECTED_NAME,
                EXPECTED_PRICE,
                EXPECTED_QUANTITY
    );
    return pr;
}
TEST(StoragedProduct,SetArguments) {
    StoragedProduct* pr = _create_product();
    EXPECT_EQ(pr->id,EXPECTED_ID);
    EXPECT_EQ(pr->name,EXPECTED_NAME);
    EXPECT_DOUBLE_EQ(pr->price,EXPECTED_PRICE);
    EXPECT_EQ(pr->quantity,EXPECTED_QUANTITY);
    delete pr;

}


TEST(StoragedProduct,CanRetireQuantity) {
   StoragedProduct* pr = _create_product();
   bool can_retire = pr->can_retire(EXPECTED_QUANTITY + 9);
   EXPECT_FALSE(can_retire);
   delete pr;

}


TEST(StoragedProduct,RetireQuantity) {
   StoragedProduct* pr = _create_product();
   const int EXPECTED_REMAINING_QTY = 1;
   bool retire = pr->retire(EXPECTED_QUANTITY - 1);
   EXPECT_TRUE(retire);
   EXPECT_EQ(pr->quantity, EXPECTED_REMAINING_QTY);
   delete pr;

}


TEST(StoragedProduct,UpdateProduct) {
   StoragedProduct* pr1 = _create_product();
   StoragedProduct* pr2 = new StoragedProduct(
                900,
                "pr2",
                99.99,
                77
    );
    pr1->update(pr2);

    EXPECT_NE(pr1,pr2);
    EXPECT_NE(pr2, nullptr);
    delete pr2;
    pr2 = nullptr;
    //std::cout << "ptr2 " << pr2->name << std::endl;
    EXPECT_EQ(pr2, nullptr);
    EXPECT_EQ(pr1->name,"pr2");
    EXPECT_DOUBLE_EQ(pr1->price,99.99);
    EXPECT_EQ(pr1->quantity,77);
    delete pr1;

}

