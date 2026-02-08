#include <gtest/gtest.h>
#include "test.h" // Se encuentra automáticamente por herencia de LogicLib

TEST(TestEjemplo, IntArgReturnSameInt) {
    int expected = 7;
    int a = test_nr(expected);
    
    EXPECT_EQ(a,expected);
}

TEST(TestEjemplo, IntArgReturnNotSameInt) {
    int expected = 8;
    int passed = 7;
    int a = test_nr(passed);
    
    EXPECT_NE(a,expected);
}