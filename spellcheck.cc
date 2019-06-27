#include "spellcheck.h"
#include <fstream>

BloomKata::SpellChecker::SpellChecker(std::string filename) {
    std::ifstream infile(filename.c_str());
    std::string word;
    while(infile >> word) {
         loaded_words.insert(word);
    }
}

bool BloomKata::SpellChecker::operator[](std::string word) {
    return loaded_words.find(word) != loaded_words.end();
}