// main.cpp 
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include "SplayTree.h"

using namespace std; 

int convertToInt(string x) {
    stringstream y(x); 
    int num = 0; 
    y >> num; 
    return num; 
}

int main() {
    std::string com;
    string num; 
    SplayTree s; 
    while (cin) {
        cin >> com; 
        if (com == "insert") {
            cin >> num; 
            s.insert(convertToInt(num)); 
            // s.printBFS(s.getRoot());
            num = ""; 
        }
        if (com == "find") {
            cin >> num; 
            s.find(convertToInt(num)); 
            // s.printBFS(s.getRoot());
            num = ""; 
        }
        if (com == "delete") {
            cin >> num; 
            s.remove(convertToInt(num)); 
            // s.printBFS(s.getRoot());
            num = ""; 
        }
        if (com == "print") {
            s.printBFS(s.getRoot());
            break; 
        }
    }

    // SplayTree s; 
    // s.split(1,s.getRoot());
    // s.insert(1);
    // s.printLevelOrder(s.root);
    // s.find(1);
    // s.printLevelOrder(s.root);
    // s.insert(3);
    // s.printLevelOrder(s.root);
    // s.insert(5);
    // s.printLevelOrder(s.root);
    // s.insert(2);
    // s.printLevelOrder(s.root);
    // s.insert(6);
    // s.printLevelOrder(s.root);
    // s.insert(6);
    // s.printLevelOrder(s.root);
    // s.remove(7);
    // s.printLevelOrder(s.root);
    // s.remove(1);
    // s.printLevelOrder(s.root);


    // fix access(i), the error is that even if the value is not in the tree, it will still splay the last value 
    //and return root, what i want is that it splays the last value and returns NULL
    
    return 0; 
}