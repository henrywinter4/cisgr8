#include "Trie2.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


Trie2::Trie2() {
    root = nullptr;
}

void Trie2::insert(string word, int num) {
    bool isInTree = false;
    Node* currNode = root;
    int numLetters = 0;

    if (search(word) == true) {
        for (size_t i = 0; i < word.size(); i++) {
            for (size_t j = 0; j < currNode->childNodes.size(); j++) {
                if (currNode->childNodes[j]->data == word[i]) {
                    Node* temp = currNode->childNodes[j];
                    currNode = temp;
                }
            }   
        }

        currNode->isEndOfWord = true;
        currNode->routerNumber = num;

        return;
    }

    if (currNode == nullptr) {
        isInTree = false;
    } else if (currNode->data == word.at(0)) {
        isInTree = true;
        numLetters++;
    } else {
        return;
    }

    while(isInTree == true) {
        if (currNode->childNodes.size() == 0) {
            isInTree = false;
            break;
        }

        for (size_t i = 0; i < currNode->childNodes.size(); i++) {

            if (currNode->childNodes[i]->data == word[numLetters]) {
             
                Node* temp = currNode->childNodes[i];
                currNode = temp;
                if (numLetters == word.size()) {
                    currNode->isEndOfWord = true;
                }
                
                numLetters++;
                isInTree = true;
                break;
            } else {
                isInTree = false;
            }
        }
        
    }


    if ((word.size() - numLetters) == 0) {
        return;
    }

    for (int i = numLetters; i < word.size(); i++) {
        Node* newNode = new Node();
        newNode->data = word[i];
        if (i == word.size() - 1) {
            newNode->isEndOfWord = true;
            newNode->routerNumber = num;
        } else {
            newNode->isEndOfWord = false;
            newNode->routerNumber = 0;
        }

        if (currNode == nullptr) {
            root = newNode;
        } else {
            (currNode->childNodes).push_back(newNode);
        }

        currNode = newNode;
    }

    return;
    
}

int Trie2::findLongestMatchingPrefix(string address) {
    bool isInTree = true;
    Node* currNode = root;
    int numbers = 1;

    while(isInTree == true) {
        if (currNode->childNodes.size() == 0) {
            isInTree = false;
            break;
        }

        for (size_t i = 0; i < currNode->childNodes.size(); i++) {
            if (currNode->childNodes[i]->data == address[numbers]) {
         
                Node* temp = currNode->childNodes[i];
                currNode = temp;
       
                numbers++;
                isInTree = true;
                break;
            } else {
                isInTree = false;
            }
        }
        
    }

    

  
    return currNode->routerNumber;

}


bool Trie2::search(string word) {
    bool isInTree = false;

    if (root == nullptr) {
        return false;
    } else if (root->data == word[0]) {
        isInTree = true;
        if (word.size() == 1) {
            return true;
        }
    }

    Node* currNode = root;
    int letterIndex = 1;

    while (isInTree == true) {
        if (currNode->childNodes.size() == 0) {
            return false;
        }

        if (letterIndex == word.size() - 1) {
            for (size_t i = 0; i < currNode->childNodes.size(); i++) {
                if (currNode->childNodes[i]->data == word[letterIndex]) {
                    isInTree = true;
                    return true;
                } else {
                    isInTree = false;
                }
            }

            return isInTree;
        } else {
            for (size_t i = 0; i < currNode->childNodes.size(); i++) {
                if (currNode->childNodes[i]->data == word[letterIndex]) {
                    isInTree = true;
                    Node* temp = currNode->childNodes[i];
                    currNode = temp;
                    break;
                } else {
                    isInTree = false;
                }
            }
        }

        letterIndex++;
    }



    return false;
}
