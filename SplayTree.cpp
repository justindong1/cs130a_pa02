// SplayTree.cpp
#include <iostream>
#include "SplayTree.h"

using namespace std; 

SplayTree::SplayTree() {
    root = NULL; 
}

Node* SplayTree::access(int i) {
    root = splay(root,i); 
    return root; 
}

Node* SplayTree::splay(Node* x, int i) {
    if (x == NULL || x->value == i) {
        return x; 
    }
    
    // left side 
    if (i < x->value) {
        if (x->left == NULL) {
            return x; 
        }
        if (i < x->left->value) {
            // case 2 step 1
            x = rotateRight(x); 
            x->left = splay(x->left, i); 
        }
        else if (i > x->left->value) {
            x->left->right = splay(x->left->right, i); 
            if (x->left->right != NULL) {
                x->left = rotateLeft(x->left);
            }
        }
        if (x->left == NULL) {
            return x;
        }
        return rotateRight(x);
    }
    else {
        if (x->right == NULL) {
            return x; 
        }
        if (x->right->value > i) {
            x->right->left = splay(x->right->left,i); 
            if (x->right->left != NULL) {
                x->right = rotateRight(x->right);
            }
        }
        else if (x->right->value < i) {
            x = rotateLeft(x); 
            x->right = splay(x->right, i);
        }
        if (x->right == NULL) {
            return x; 
        }
        return rotateLeft(x); 
    }
}

// all keys in t1 are less than those in t2 
Node* SplayTree::join(Node* t1, Node* t2) {
    if (t1 == NULL) {
        return t2; 
    }
    if (t2 == NULL) {
        return t1; 
    }
    Node* n = getMax(t1); 
    Node* q = access(n->value); 
    q->right = t2; 
    return q; 
} 

std::pair<Node*, Node*> SplayTree::split(int i, Node* n) {
    Node* x = access(i); 
    if (x == NULL) {
        pair<Node*, Node*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    if (x->value > i) {
        Node* y = x->left; 
        x->left = NULL; 
        pair<Node*, Node*> p;
        p.first = y; 
        p.second = x; 
        return p; 
    }
    Node *y = x->right; 
    x->right = NULL; 
    pair<Node*, Node*> p; 
    p.first = x; 
    p.second = y; 
    return p; 
}

void SplayTree::find(int i) {
    Node* x = access(i); 
    if (x->value == i) {
        cout << "item " << i << " found" << endl; 
    }
    else {
        cout << "item " << i << " not found" << endl; 
    }
}

void SplayTree::insert(int i) {
    if (root != NULL && access(i)-> value == i) {
        cout << "item " << i << " not inserted; already present" << endl;
    }
    else {
        pair<Node*,Node*> n = split(i, root); 
        Node* p = new Node(i); 
        p->left = n.first; 
        p->right = n.second;
        root = p; 
        cout << "item " << i << " inserted " << endl;
    }
}

void SplayTree::remove(int i) {
    Node* n = access(i); 
    if (root != NULL && n->value == i) {
        root = join(n->left, n->right); 
        cout << "item " << i << " deleted" << endl; 
    }
    else {
        cout << "item " << i << " not deleted; not present" << endl; 
    }
}

void SplayTree::printBFS(Node* n) {
    int h = height(n); 
    int i; 
    for (i=1; i<=h; i++) {
        printLevel(n, i); 
        cout << "\n";
    }
}

Node* SplayTree::getRoot() {
    return root; 
}

Node* SplayTree::rotateRight(Node* x) {
    Node* n = x->left; 
    x->left = n->right; 
    n->right = x; 
    return n;
}

Node* SplayTree::rotateLeft(Node* x) {
    Node* n = x->right; 
    x->right = n->left; 
    n->left = x; 
    return n; 
}

Node* SplayTree::getMax(Node* x) {
    Node* n = x; 
    while(n->right != NULL) {
        n=n->right; 
    }
    return n;
}

void SplayTree::printLevel(Node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) {
        cout << root-> value << " "; 
    }
    else if (level > 1) 
    { 
        printLevel(root->left, level-1); 
        printLevel(root->right, level-1); 
    } 
} 

int SplayTree::height(Node* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        int heightLeft = height(node->left); 
        int heightRight = height(node->right); 
        if (heightLeft > heightRight) {
            return(heightLeft+1); 
        }
        else {
            return(heightRight+1); 
        }
    } 
} 