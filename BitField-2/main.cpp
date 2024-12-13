#include <gtest/gtest.h>
#include <gmock/gmock.h>


int main(int argc, char **argv) {
    uint16_t mask = 9;
    std::cout << (mask << (4 & 15)) << std::endl;
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}