#include "Trie.h"
#include <vector>
#include <string>

using namespace std;
Trie::Trie(){
    Node * root = nullptr;
}
void Trie::insert(string value){
    Node *currNode = root;
    Node* newNode = nullptr;
    bool dataFound = true;
    int iterator;
    //    if (search(value) == true) {
    //     for (int i = 0; i < value.size(); i++) {
    //         for (int j = 0; j < currNode->childNodes.size(); j++) {
    //             if (currNode->childNodes[j]->data == value[i]) {
    //                 // Update currNode
    //                 Trie::Node* temp = currNode->childNodes[j];
    //                 currNode = temp;
    //             }
    //         }   
    //     }

    //     // Set to end
    //     currNode->isEndOfWord = true;

    //     return;
    // }
            
    if(currNode ==  nullptr){
        dataFound = false;
    } else if (currNode->data == value.at(0)) {
        dataFound = true;
        iterator++;
    } else {
        return;
    }
 
    while(dataFound == true && iterator > value.size()){
        if(currNode->childNodes.size() <= 0){
            dataFound = false;
            break;
        }

            for(int i = 0; i < currNode->childNodes.size(); i++){

        if (currNode->childNodes[i]->data == value[iterator]) {
           
                Node* temp = currNode->childNodes[i];
                currNode = temp;
                if (iterator == value.size()) {
                    currNode->isEndOfWord = true;
                }
                
                // Update numLetters
                iterator++;
                dataFound = true;
                break;
            } else {
                // Reached end of path, end loop
                dataFound = false;
            }

            }
        
        iterator++;
    }
        if ((value.size() - iterator) == 0) {
        return;
    }
    for(int i = iterator; i < value.size(); i++){

        
        if(dataFound == false){
            newNode = new Node();
            newNode->data = value[i];
            currNode->childNodes.push_back(newNode);
            currNode = newNode;    
        }
    }
}
// bool Trie::search(string value){
//     Node* currNode = root;
//     Node* nextNode = nullptr;
//     Node* testNode = nullptr;
//     for(int i = 0; i < value.length(); i++){
//         for(int j = 0; j < currNode->childNodes.size(); j++){
//             testNode = currNode->childNodes[j];
//             if(testNode->data == value[i]){
//                 nextNode = testNode;
//             }
            
//         }
//         if(nextNode == currNode || nextNode == nullptr){
//             return false;
//         }
//         currNode = nextNode;
    

//     }
//     return true;

// }
vector<string> Trie::getSuggestions(string partialWord){
    // vector<string> suggestions;
    // for(int i = 0; i < wordbank.size(); i++){
    //     bool found = true;
    //     Node *currNode = root;
    //     Node *nextNode = nullptr;
    //     Node *testNode = nullptr;
    //     for(int j = 0; j < partialWord.size(); j++){
    //         for(int k = 0; k < currNode->childNodes.size(); k++){
    //             testNode = currNode->childNodes[k];
    //             if(testNode->data != partialWord[j]){
    //                 found = false;
    //             } else {
    //                 nextNode = testNode;
    //             }

    //         }

    //     }
    // if(found == false){
    //     //remove word from suggestions
    // }
    // }
    // return suggestions;
}
