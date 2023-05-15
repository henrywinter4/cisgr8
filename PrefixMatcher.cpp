#include "PrefixMatcher.h"
#include "Trie2.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void PrefixMatcher::insert(std::string address, int routerNumber) {
    t.insert(address, routerNumber);
}

int PrefixMatcher::selectRouter(string networkAddress) {
    return t.findLongestMatchingPrefix(networkAddress);
}
