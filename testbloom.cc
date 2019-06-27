#include "spellcheck.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(BloomTest, BaseTest) {
    BloomKata::SpellChecker speller("wordlist.txt");
    std::cout << "Loaded words: " << speller.size() << std::endl;
    ASSERT_TRUE(speller["cool"]);
    ASSERT_FALSE(speller["COOL"]);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    auto retval = RUN_ALL_TESTS();
}
