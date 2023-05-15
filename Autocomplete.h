#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include "Trie.h"
#include <string>
#include <vector>
class Trie;
class Autocomplete{
    private:
        Trie t;
    public:
        void insert(std::string value);
        std::vector<std::string> getSuggestions(std::string partialWord);
};

#endif