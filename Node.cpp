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

// Function to rotate Left based off the root
Node* Node::rotateLeft ( Node* root ) {

    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    return child;
}

// Function to rotate right based off the root
Node* Node::rotateRight ( Node* root ) {

    Node *child = root->left;
    Node *childRight =  child->right;

    child->right = root;
    root->left = childRight;

    return child;
}

Node* Node::Insert ( int Data ) {

    // Color is set to red

    if ( root == nullptr ) {

        Node* newNode;
        newNode->data = data;
        return newNode;

    }

    if ( data >= root->data ) {

        root->right = Insert( data, root->right );

    } else if ( data < root->data ) {

        root->left = Insert( data, root->left );

    }

    // Case for when the left child is black/nullptr and the right child is red
    if ( root->right->isRed && ( !( root->left->isRed )  || root->left == nullptr ) ) {

        root = rotateLeft( root );
        root.changeColor();
        root->left.changeColor();

    }

    // Case for when left child & left grandchild are red
    if ( root->left->isRed && root->left->left->isRed ) {

        root = rotateRight( root );
        root.changeColor();
        root->right.changeColor();

    }

    if ( root->right->isRed && !( root->left->isRed ) ) {

        root = rotateLeft( root );
        root.changeColor();
        root->left.changeColor();

    }

    // Case when both left and right child are Red in color
    if ( root->left->isRed && root->right->isRed ) {

        root->isRed = !( myNode->isRed );

        // Change the color to black.
        root->left->isRed = false;
        root->right->isRed = false;
    }

    // Return the root for the current recursion call to keep order of tree
    return root;
}

void changeColor () {

    this->isRed = !( this->isRed );

}

bool SearchFor ( int value, Node* root ) {

    if ( root->data == value ) {

        // Data exists in tree
        // !!!!!! If we have to give exact location then this is more in depth fs !!!!!!
        return true;

    }





}
