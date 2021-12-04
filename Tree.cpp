#include "Tree.h"

#include <iostream>
#include <string>

// Default constructor
Tree::Tree() {

    this->root = NULL;

}

// Deconstructor
Tree::~Tree() {

    delete this->root;

}

// Custom constructor if given a root
Tree::Tree( Node* root ) {

    this->root = root;

}

// --------------------------------------------------------------
// Function is a private insert function that takes data and
// a root node, then inserts the node at the specific location
// of the tree, depending on the right circumstances
// --------------------------------------------------------------
Node* Tree::Insert ( std::string data, Node* root ) {

    //std::cout << "Attempting to insert: " << data << ", into the tree!" << std::endl;

    // Base case: when the Node reached is a nullptr, then the data has found it's place to make a node
    if ( root == nullptr ) {

        //std::cout << "Inserted " << data << " successfully!" << std::endl;
        return new Node ( data );

    }

    // Checks if the data is >= to the data of the root, if it is then it will move to the right
    if ( data >= root->data ) {

        std::cout << "Moved right" << std::endl;
        root->right = Insert( data, root->right );

    }
    // Checks if the data is < to the data of the root, if it is then it will move to the left
    else {

        std::cout << "Moved left" << std::endl;
        root->left = Insert( data, root->left );

    }


    // Case for when the left child is black/nullptr and the right child is red
    if ( root->right != nullptr && ( root->left == nullptr || root->left->isRed == false ) ) {

        if ( root->right->isRed && !( root->left->isRed ) ) {

            std::cout << "Met first criteria" << std::endl;
            root = rotateLeft ( root );

            // Swap colors of root and it's left leg
            if ( root->isRed != root->left->isRed ) {

                bool color = root->isRed;
                root->isRed = root->left->isRed;
                root->left->isRed = color;

            }

        }

    }

    // Case for when left child & left grandchild are red

    if ( root->left != nullptr & root->left->left != nullptr ) {

        if ( root->left->isRed && root->left->left->isRed ) {

            std::cout << "Met second criteria" << std::endl;
            root = rotateRight( root );

            // Swap colors of root and it's right leg
            if ( root->isRed != root->right->isRed ) {

                bool color = root->isRed;
                root->isRed = root->right->isRed;
                root->right->isRed = color;

            }

        }

    }

    // Case when both left and right child are Red in color
    if ( root->left != nullptr && root->right != nullptr ) {

        if ( root->left->isRed && root->right->isRed ) {

            std::cout << "Met third criteria" << std::endl;
            root->isRed = !root->isRed;

            // Change the color of both legs to black.
            root->left->isRed = false;
            root->right->isRed =  false;
        }

    }

    // Return the root for the current recursion call to keep order of tree
    return root;
}

// ------------------------------------------------
// Function is a public insert function that takes
// data and calls the private insert function
// ------------------------------------------------
void Tree::Insert ( std::string data ) {

    // This is the public insert
    std::cout << "Public insert called" << std::endl;
    this->root = this->Insert( data, this->root );
    std::cout << "Inserted" << std::endl;
    this->root->isRed = false;

}


// ------------------------------------------------
// Function to rotate Left based off the root
// ------------------------------------------------
Node* Tree::rotateLeft ( Node* root ) {

    // Create copy node of the root's right child
    Node *child = root->right;

    // Create copy node of the root's left child
    Node *leftGrandChild = root->right->left;

    // Set the root's right leg's node left leg's node as the root node's value
    root->right->left = root;

    // Set the root's right leg node as the childLeft node
    root->right = leftGrandChild;

    std::cout << "Rotated left!" << std::endl;
    return child;
}

// ------------------------------------------------
// Function to rotate right based off the root
// ------------------------------------------------
Node* Tree::rotateRight ( Node* root ) {

    Node *child = root->left;
    Node *rightGrandChild =  root->left->right;

    root->left->right = root;
    root->left = rightGrandChild;

    std::cout << "Rotated right!" << std::endl;
    return child;
}





// -----------------------------------------------------------
// Search function to find if the value is in the tree or not
// -----------------------------------------------------------
bool Tree::SearchFor ( std::string value, Node* root ) {

    // Base case: if the root's data is the same as the data given by the user
    if ( root->data == value ) {

        // Data exists in tree, return true
        return true;

    }

    // Check if the value given is
    if ( value >= root->data ) {

        return SearchFor ( value, root->right );

    } else if ( value < root->data ) {

        return SearchFor ( value, root->left );

    }

    // Not too sure if this is needed
    return false;

}
