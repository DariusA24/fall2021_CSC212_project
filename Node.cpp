#include "node.h"

// Default constructor
Node::Node() {

    this->data = 0;
    this->isRed = false;
    this->left = nullptr;
    this->right = nullptr;

}

// Deconstructor
Node::~Node() {

    if ( this->left != nullptr ) {

        delete this->left;

    }

    if ( this->right != nullptr ) {

        delete this->right;

    }

}

// Custom constructor
Node::Node ( int data ) {

    // Create node with the data value and make it red
    this->data = data;
    this->isRed = true;
    
    // Both legs are nullptr, they don't exist yet
    this->left = nullptr;
    this->right = nullptr;

}

// Function to rotate Left based off the root
Node* Node::rotateLeft ( Node* root ) {

    // Create copy node of the root's right child
    Node *child = root->right;
    
    // Create copy node of the root's left child
    Node *childLeft = child->left;

    // Set the root's right leg's node left leg's node as the root node's value
    child->left = root;
    
    // Set the root's right leg node as the childLeft node
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
        
        // Swap colors of root and it's left leg
        if ( !( root->isRed == root->left->isRed ) ) {
            
            bool color = root->isRed;
            root->isRed = root->left->isRed;
            root->left->isRed = color;
            
        }
        
    }

    // Case for when left child & left grandchild are red
    if ( root->left->isRed && root->left->left->isRed ) {

        root = rotateRight( root );
        
        // Swap colors of root and it's right leg
        if ( !( root->isRed == root->right->isRed ) ) {
            
            bool color = root->isRed;
            root->isRed = root->right->isRed;
            root->right->isRed = color;
            
        }

    }

    if ( root->right->isRed && !( root->left->isRed ) ) {

        root = rotateLeft( root );
        
        // Swap colors of root and it's left leg
        if ( !( root->isRed == root->left->isRed ) ) {
            
            bool color = root->isRed;
            root->isRed = root->left->isRed;
            root->left->isRed = color;
            
        }

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

        // Data exists in tree, return true
        // !!!!!! If we have to give exact location then this is more in depth fs !!!!!!
        return true;

    }

    if ( value >= root->data ) {

        SearchFor ( value, root->right );

    } else if ( value < root->data ) {

        SearchFor ( value, root->left );

    }
    
    return false;
    
}
