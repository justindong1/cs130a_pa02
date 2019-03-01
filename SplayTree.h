// SplayTree.h
#include <iostream>
#include <utility>

#ifndef SPLAYTREE_H
#define SPLAYTREE_H

struct Node {
    int value; 
    Node* left;
    Node* right; 
    Node* parent; 

    Node(int i) : value(i), left(0), right(0) {}
};

class SplayTree {
    public:
        SplayTree(); 
        Node* access(int i); 
        Node* splay(Node* x, int i); 
        Node* join(Node* t1, Node* t2);
        std::pair<Node*, Node*> split(int i, Node* n);
        void find(int i); 
        void insert(int i); 
        void remove(int i);
        void printBFS(Node *n);  

        Node* getRoot(); 
        Node* rotateRight(Node* x); 
        Node* rotateLeft(Node* x); 
        Node* getMax(Node* x); 

        void printLevel(Node* root, int level);
        int height(Node* node);

    private: 
        Node* root;
        
};

#endif // SPLAYTREE_H