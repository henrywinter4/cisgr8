#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include "Trie2.h"
#include<string>


class PrefixMatcher {
    private:
        Trie2 t;
    public:
        int selectRouter(std::string networkAddress); 
        void insert(std::string address, int routerNumber);

};

#endif 