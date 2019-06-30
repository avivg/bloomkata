#include "spellcheck.h"
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <bitset>

BloomKata::ReferenceResult::ReferenceResult(const std::string& filename) {
    std::ifstream infile(filename.c_str());
    std::string word;
    while(infile >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        loaded_words.insert(word);
    }
}

const bool BloomKata::ReferenceResult::operator[](std::string word) const {
    return loaded_words.find(word) != loaded_words.end();
}

BloomKata::StdSpellCheck::StdSpellCheck(const std::string& filename) {
    std::ifstream infile(filename.c_str());
    std::string word;
    while(infile >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        found.set(word_bit_idx(word));
    }
}

const bool BloomKata::StdSpellCheck::operator[](std::string word) const {
    return found.test(word_bit_idx(word));
}

const size_t BloomKata::StdSpellCheck::word_bit_idx(std::string word) {
    auto hashval = std::hash<std::string>()(word);
    return (hashval % nof_bits);

}
