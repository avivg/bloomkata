#include "spellcheck.h"
#include <gtest/gtest.h>
#include <iostream>
#include <random>

const char *dictfile = "wordlist.txt";

TEST(BloomTest, BaseTest) {
    BloomKata::ReferenceResult reference(dictfile);
    std::cout << "Loaded words: " << reference.size() << std::endl;
    ASSERT_TRUE(reference["cool"]);
    ASSERT_FALSE(reference["sdfgsgers"]);
}

std::string get_rand_word() {
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> char_dist(0,'z' - 'a');
    constexpr int len = 5;
    char ret[6];
    for (int i = 0; i < len; i++) {
        ret[i] = 'a' + char_dist(generator);
    }
    ret[len] = '\0';
    return std::string(ret);
}

TEST(BloomTest, StdTest) {
    BloomKata::ReferenceResult reference(dictfile);
    BloomKata::StdSpellCheck spell(dictfile);
    constexpr unsigned long tests = 1000000ul;
    int false_positives = 0;
    int real_words = 0;
    for (int i = tests; i --> 0;) {
        auto word = get_rand_word();
        if (reference[word]) {
            real_words++;
            ASSERT_TRUE(spell[word]);
        } else if (spell[word]) {
            false_positives++;
        }
    }
    std::cout << "False-Positives: " << false_positives << std::endl;
    std::cout << "Real words: " << real_words << std::endl;
    std::cout << "Rate: " << std::fixed << std::setprecision(2)
              << 100.0 * false_positives / (tests - real_words)
              << "%"
              << std::endl;
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    auto retval = RUN_ALL_TESTS();
}
