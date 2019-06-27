#ifndef BLOOMKATA_SPELLCHECK__
#define BLOOMKATA_SPELLCHECK__

#include <string>
#include <set>

namespace BloomKata {
    class SpellChecker {
    public:
        SpellChecker(std::string wordlistfile);
        bool operator[](std::string word);
        size_t size() {return loaded_words.size();}
    
    private:
        std::set<std::string> loaded_words;
    };
};

#endif // BLOOMKATA_SPELLCHECK__