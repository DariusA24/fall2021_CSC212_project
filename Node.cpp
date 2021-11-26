#include "Node.hpp"

Node::Node() {

    this->data = 0;
    this->isRed = false;
    this->left = nullptr;
    this->right = nullptr;

}

Node::~Node() {

    if ( this->left != nullptr) {

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

Node* Node::Insert ( int Data, Node* root ) {

    if ( root == nullptr ) {

        Node* newNode ( data );
        return newNode;

    }

    if ( data >= root->data ) {

        root->right = insert( data, root->right );

    } else if ( data < root->data ) {

        root->left = insert( data, root->left );

    }

    // Rotate checks need to be done here
    // Recolor checks done after the rotate?
    
    return root;

}
