
#include <gtest/gtest.h>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST(JANSON, CreateAndSelectionJson) {
    json ex1 = json::parse(R"(
        {   
            "str": "hola",
            "pi": 3.141,
            "happy": true
        }
    )");

    EXPECT_EQ(ex1["str"], "hola");
}