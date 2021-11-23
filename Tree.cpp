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
