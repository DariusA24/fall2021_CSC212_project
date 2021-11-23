#include "node.h"
#include <iostream>

Tree() {

    this->root = nullptr;

}

~Tree() {

    delete this->root;

}

Tree( Node* root ) {

    this->root = root;

}

Node* Tree::insert ( int data ) {

    // This is the public insert
}


Node* Tree::rotateLeft ( Node* root ) {

    node *child = root->right;
    node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    return child;
}


Node* rotateRight ( Node* root ) {

    node *child = root->left;
    node *childRight =  child->right;

    child->right = root;
    root->left = childRight;

    return child;
}
