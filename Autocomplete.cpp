#include "Autocomplete.h"
#include "Trie.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void Autocomplete::insert(string value) {
    t.insert(value);


}

vector<string> Autocomplete::getSuggestions(string partialWord) {
    vector<string> suggestions = t.getSuggestions(partialWord);
    return suggestions;
}