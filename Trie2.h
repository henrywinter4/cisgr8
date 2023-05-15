#ifndef TRIE_H
#define TRIE_H

#include<vector>
#include<string>
#include <unordered_map>


class Trie2 {
    private:
        struct Node
        {
            char data;
            std::vector<Node *> childNodes;
            bool wordEnd;
            int routerCount;
        };

        Node* root;
    public:
        Trie2();
        void insert(std::string address, int num);
        bool search(std::string value);
        int findLongestMatchingPrefix(std::string address);
};

#endif 