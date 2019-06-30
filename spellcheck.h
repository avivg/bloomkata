#ifndef BLOOMKATA_SPELLCHECK__
#define BLOOMKATA_SPELLCHECK__

#include <string>
#include <set>
#include <bitset>

namespace BloomKata {
    constexpr size_t nof_bits = 8 * 1024 * 1024ul; // 1MB

    class ReferenceResult {
    public:
        ReferenceResult(const std::string& wordlistfile);
        bool operator[](std::string word) const;
        size_t size() const {return loaded_words.size();}
    
    private:
        std::set<std::string> loaded_words;
    };

    class StdSpellCheck {

    public:
        StdSpellCheck(const std::string& wordlistfile);
        bool operator[](std::string word) const;

    private:
        std::bitset<nof_bits> found;
        static inline size_t word_bit_idx(std::string word);
    };
}

#endif // BLOOMKATA_SPELLCHECK__