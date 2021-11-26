#include "Node.hpp"
#include "Tree.hpp"
#include <iostream>

Tree::Tree() {

    this->root = nullptr;

}

Tree::~Tree() {

    delete this->root;

}

Tree::Tree( Node* root ) {

    this->root = root;

}

Node* Tree::insert ( int data  ) {

    // This is the public insert
}

// Function to rotate left based off the root
Node* Tree::rotateLeft ( Node* root ) {

    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    return child;
}

// Function to rotate right based off the root
Node* rotateRight ( Node* root ) {

    Node *child = root->left;
    Node *childRight =  child->right;

    child->right = root;
    root->left = childRight;

    return child;
}
