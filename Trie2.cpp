#include "Trie2.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


Trie2::Trie2() {
    root = nullptr;
}

void Trie2::insert(string value, int num) {
    bool wordEnd = false;
    Node* currNode = root;
    int numLetters = 0;

    if (search(value) == true) {
        for (size_t i = 0; i < value.size(); i++) {
            for (size_t j = 0; j < currNode->childNodes.size(); j++) {
                if (currNode->childNodes[j]->data == value[i]) {
                    Node* temp = currNode->childNodes[j];
                    currNode = temp;
                }
            }   
        }

        currNode->wordEnd = true;
        currNode->routerCount = num;

        return;
    }

    if (currNode == nullptr) {
        wordEnd = false;
    } else if (currNode->data == value.at(0)) {
        wordEnd = true;
        numLetters++;
    } else {
        return;
    }

    while(wordEnd == true) {
        if (currNode->childNodes.size() == 0) {
            wordEnd = false;
            break;
        }

        for (size_t i = 0; i < currNode->childNodes.size(); i++) {

            if (currNode->childNodes[i]->data == value[numLetters]) {
             
                Node* temp = currNode->childNodes[i];
                currNode = temp;
                if (numLetters == value.size()) {
                    currNode->wordEnd = true;
                }
                
                numLetters++;
                wordEnd = true;
                break;
            } else {
                wordEnd = false;
            }
        }
        
    }


    if ((value.size() - numLetters) == 0) {
        return;
    }

    for (int i = numLetters; i < value.size(); i++) {
        Node* newNode = new Node();
        newNode->data = value[i];
        if (i == value.size() - 1) {
            newNode->wordEnd = true;
            newNode->routerCount = num;
        } else {
            newNode->wordEnd = false;
            newNode->routerCount = 0;
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
    bool wordEnd = true;
    Node* currNode = root;
    int numbers = 1;

    while(wordEnd == true) {
        if (currNode->childNodes.size() == 0) {
            wordEnd = false;
            break;
        }

        for (size_t i = 0; i < currNode->childNodes.size(); i++) {
            if (currNode->childNodes[i]->data == address[numbers]) {
         
                Node* temp = currNode->childNodes[i];
                currNode = temp;
       
                numbers++;
                wordEnd = true;
                break;
            } else {
                wordEnd = false;
            }
        }
        
    }

    

  
    return currNode->routerCount;

}


bool Trie2::search(string value) {
    bool wordEnd = false;

    if (root == nullptr) {
        return false;
    } else if (root->data == value[0]) {
        wordEnd = true;
        if (value.size() == 1) {
            return true;
        }
    }

    Node* currNode = root;
    int letterIndex = 1;

    while (wordEnd == true) {
        if (currNode->childNodes.size() == 0) {
            return false;
        }

        if (letterIndex == value.size() - 1) {
            for (size_t i = 0; i < currNode->childNodes.size(); i++) {
                if (currNode->childNodes[i]->data == value[letterIndex]) {
                    wordEnd = true;
                    return true;
                } else {
                    wordEnd = false;
                }
            }

            return wordEnd;
        } else {
            for (size_t i = 0; i < currNode->childNodes.size(); i++) {
                if (currNode->childNodes[i]->data == value[letterIndex]) {
                    wordEnd = true;
                    Node* temp = currNode->childNodes[i];
                    currNode = temp;
                    break;
                } else {
                    wordEnd = false;
                }
            }
        }

        letterIndex++;
    }



    return false;
}
