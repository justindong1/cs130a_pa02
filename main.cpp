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
            num = ""; 
        }
        if (com == "find") {
            cin >> num; 
            s.find(convertToInt(num)); 
            num = ""; 
        }
        if (com == "delete") {
            cin >> num; 
            s.remove(convertToInt(num)); 
            num = ""; 
        }
        if (com == "print") {
            s.printBFS(s.getRoot());
            break; 
        }
    }
    return 0; 
}