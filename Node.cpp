#include "node.h"

Node::Node() {

    this->data = 0;
    this->isRed = false;
    this->left = nullptr;
    this->right = nullptr;

}

Node::~Node() {

    if ( this->left != nullptr ) {

        delete this->left;

    }

    if ( this->right != nullptr ) {

        delete this->right;

    }

}

Node::Node ( int data ) {

    this->data = data;
    this->isRed = true;
    this->left = nullptr;
    this->right = nullptr;

}

Node* Node::Insert ( int Data ) {

    // Color is set to red


}
