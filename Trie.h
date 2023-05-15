
#ifndef TRIE_H
#define TRIE_H
#include <vector>
#include <string>
class Trie
{
    private:

    struct Node
    
    {
        char data;
        std::vector<Node *> childNodes;
        bool isEndOfWord;
    };
    Node *root;
    public:
    Trie();

    void insert(std::string value);


    bool search(std::string value);
    std::vector<std::string> getSuggestions(std::string partialWord);

};
#endif
