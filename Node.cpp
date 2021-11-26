#include "Node.hpp"

Node::Node() {

    this->data = 0;
    this->isRed = false;
    this->left = NULL;
    this->right = NULL;

}

Node::~Node() {

    if ( this->left != NULL) {

        delete this->left;

    }

    if ( this->right != NULL ) {

        delete this->right;

    }

}

Node::Node ( int data ) {

    this->data = data;
    this->isRed = true;
    this->left = NULL;
    this->right = NULL;

}

Node* Node::Insert ( int Data, Node* root ) {

    if ( root == NULL ) {

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
