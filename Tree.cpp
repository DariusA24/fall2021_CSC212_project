#include "Tree.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//                     _,,......_
//                  ,-'          `'--.
//               ,-'  _              '-.
//      (`.    ,'   ,  `-.              `.                      ____________________
//       \ \  -    / )    \               \                     |   Leon Hartley   |
//       `\`-^^^, )/      |     /         :                     |  Darius Argueta  |
//          )^ ^ ^V/            /          '.                   | Armani Fernandez |
//          |      )            |           `.                  | December 6, 2021 |
//          9   9 /,--,\    |._:`         .._`.                 -------\   /--------
//          |    /   /  `.  \    `.      (   `.`.                       | |
//          |   / \  \    \  \     `--\   )    `.`.___                  | |
//         .;;./  '   )   '   )       ///'       `-"'                   | |
//         `--'   7//\    ///\                                          | |


// Default constructor
Tree::Tree() {

    this->root = NULL;

}

// Deconstructor
Tree::~Tree() {

    deleteTree ( this->root );

}

// Custom constructor if given a root
Tree::Tree( Node* root ) {

    this->root = root;

}

// -----------------
// Public functions
// -----------------

// ------------------------------------------------
// Public insert function
// Function is a public insert function that takes
// data and calls the private insert function
// ------------------------------------------------
void Tree::Insert ( std::string data ) {

    // This is the public insert
    this->root = this->Insert( data, this->root );
    this->root->isRed = false;

}

// -----------------------
// Public height function
// -----------------------
int Tree::height () {

    std::cout << this->height ( this->root ) <<std::endl;
    return this->height ( this->root );

}

// -----------------------
// Public search function
// -----------------------
bool Tree::Search ( std::string data ) {

    return this->SearchFor ( data, this->root );

}

// -----------------------
// Public count function
// -----------------------
int Tree::Count ( std::string data ) {

    if ( this->root == nullptr ) {

        return -1;

    } else {

        return this->Count ( this->root, data );

    }
}

// ------------------
// Private Functions
// ------------------

// --------------------------------------------------------
// Function to return if the root is red in color or black
// --------------------------------------------------------
bool Tree::color ( Node* root ) {

    if ( root == nullptr ) {

        return false;

    }

    if ( root->isRed == true ) {
        return true;
    } else {
        return false;
    }

}


// --------------------------------------------------------------
// Function is a private insert function that takes data and
// a root node, then inserts the node at the specific location
// of the tree, depending on the right circumstances
// --------------------------------------------------------------
Node* Tree::Insert ( std::string data, Node* root ) {

    // Base case: when the Node reached is a nullptr, then the data has found it's place to make a node
    if ( root == nullptr ) {

        return new Node ( data );

    }

    // Checks if the data is >= to the data of the root, if it is then it will move to the right
    if ( data >= root->data ) {

        //std::cout << "Moved right" << std::endl;
        root->right = Insert( data, root->right );

    }
    // Checks if the data is < to the data of the root, if it is then it will move to the left
    else if ( data < root->data ) {

        //std::cout << "Moved left" << std::endl;
        root->left = Insert( data, root->left );
    }

    else {

        return root;

    }

    // Case for when the left child is black/nullptr and the right child is red
    if ( color ( root->right ) && color ( root->left ) == false ) {

        //std::cout << "Met first criteria" << std::endl;
        root = rotateLeft ( root );

        // Swap colors of root and it's left leg
        if ( root->isRed != root->left->isRed ) {

            bool color = root->isRed;
            root->isRed = root->left->isRed;
            root->left->isRed = color;

        }

    }

    // Case for when left child & left grandchild are red
    if ( color ( root->left ) && color ( root->left->left ) ) {

        //std::cout << "Met second criteria" << std::endl;
        root = rotateRight( root );

        // Swap colors of root and it's right leg
        if ( root->isRed != root->right->isRed ) {

            bool color = root->isRed;
            root->isRed = root->right->isRed;
            root->right->isRed = color;

        }

    }

    // Case when both left and right child are Red in color
    if ( color ( root->left ) && color ( root->right ) ) {

        //std::cout << "Met third criteria" << std::endl;
        root->isRed = !root->isRed;

        // Change the color of both legs to black.
        root->left->isRed = false;
        root->right->isRed =  false;

    }

    // Return the root for the current recursion call to keep order of tree
    return root;
}


// ---------------------------------------------------
// Function to find and return the height of the tree
// ---------------------------------------------------
int Tree::height ( Node* root ) {

    // If the tree is empty / root node is a nullptr return -1 to the count
    if ( root == nullptr ) {

        return -1;

    }

    int left = height ( root->left );
    int right = height ( root->right );

    return ( left > right ? left + 1 : right + 1 );

}


// ----------------------------------------------------------------------------------------------------------------
// Function that will go through the tree in a preorder formation ( ROOT THEN LEFT THEN ROOT ), makes copy of tree
// ----------------------------------------------------------------------------------------------------------------
void Tree::preorder ( Node* root ) {

    if ( root == nullptr ) {

        return;

    }

    std::cout << root->data << ":" << root->isRed << ", ";
    this->preorder( root->left );
    this->preorder( root->right );

    return;
}

// -----------------------------------------------------------------------------------------------------------
// Function that will go through the tree in a inorder formation ( LEFT THEN ROOT THEN RIGHT ), searches tree
// -----------------------------------------------------------------------------------------------------------
void Tree::inorder ( Node* root ) {

    if ( root == nullptr ) {

        return;

    }

    this->inorder( root->left );
    std::cout << root->data << ":" << root->isRed << ", ";
    this->inorder( root->right );

    return;
}

// -------------------------------------------------------------------------------------------------------------
// Function that will go through the tree in a postorder formation ( LEFT THEN RIGHT THEN ROOT ), deleting tree
// -------------------------------------------------------------------------------------------------------------
void Tree::postorder ( Node* root ) {

    if ( root == nullptr ) {

        return;

    }

    this->postorder( root->left );
    this->postorder( root->right );
    std::cout << root->data << ":" << root->isRed << ", ";

    return;
}

// ------------------------------------------------
// Function to rotate Left based off the root
// ------------------------------------------------
Node* Tree::rotateLeft ( Node* root ) {

    // Create copy node of the root's right child
    Node *child = root->right;

    // Create copy node of the root's right child's left child
    Node *leftRightGrandChild = root->right->left;

    // Set the root's right leg's node left leg's node as the root node's value
    root->right->left = root;

    // Set the root's right leg node as the leftRightGrandChild node
    root->right = leftRightGrandChild;

    //std::cout << "Rotated left!" << std::endl;
    return child;
}

// ------------------------------------------------
// Function to rotate right based off the root
// ------------------------------------------------
Node* Tree::rotateRight ( Node* root ) {

    // Create copy node of the root's left child
    Node *child = root->left;

    // Create copy node of the root's left child's right child
    Node *rightLeftGrandChild =  root->left->right;

    // Set the root's left leg's node right leg's node as the root node's value
    root->left->right = root;

    // Set the root's left leg node as the rightLeftGrandChild node
    root->left = rightLeftGrandChild;

    //std::cout << "Rotated right!" << std::endl;
    return child;
}

// ---------------------------------------------------------------------------
// Search function to find count of duplicates of a certain value in the tree
// ---------------------------------------------------------------------------
int Tree::Count ( Node* root, std::string key ) {

    // If the root is non existant dont add anything to the count
    if ( root == nullptr ) {

        return 0;

    }
    // If the key matches the root's data, add one to the count and continue the search in pre-order way
    else if ( root->data == key ) {

        return Count ( root->left, key ) + 1 + Count ( root->right, key );

    }
    // If the key doesnt match the root's data, continue the search in pre-order way
    else {

        return Count ( root->left, key ) + Count ( root->right, key );

    }

}

// -----------------------------------------------------------
// Search function to find if the value is in the tree or not
// -----------------------------------------------------------
bool Tree::SearchFor ( std::string key, Node* root ) {

    // Tree either doesnt exist at the first recursion call, or the tree reaches it's last branch and doesn't find the node
    if ( root == nullptr ) {

        return false;

    }

    // Base case: if the root's data is the same as the data given by the user
    if ( root->data == key ) {

        // Data exists in tree, return true
        return true;

    }

    // Check if the key given is > the root's value
    if ( key >= root->data ) {

        // Calls itself again using the root's right child as the new root
        return this->SearchFor ( key, root->right );

    } else {

        // Calls itself again using the root's left child as the new root
        return this->SearchFor ( key, root->left );

    }

}

// -----------------------------------------------------------
// Function that generates a digraph output file for graphviz
// -----------------------------------------------------------
void Tree::generateDigraph ( std::string fileName ) {

    // Opens the outfile file, prepares it for writing
    std::ofstream outputFile( fileName );

    // Write the first line
    outputFile << "digraph G {" << "\n\n";

    // Create vector to hold each line for the dot file
    std::vector<std::string> dotLines;

    // Call traverse digraph function to search through tree for every edge in a preorder fashion
    TraverseDigraph ( this->root, dotLines );

    // Loop to write each line from the dotLines vector to the output file
    for ( int i = 0; i < dotLines.size(); i++ ) {

        outputFile << dotLines[i];

    }

    // Write final line
    outputFile << "\n}";

    // Closes file
    outputFile.close();

}

// --------------------------------------------------------------------------------------------------
// Function that traverses the BST and adds to a vector a edge declaration for graphviz to interpret
// --------------------------------------------------------------------------------------------------
void Tree::TraverseDigraph ( Node* root, std::vector<std::string> &dotLines ) {

    // Traversed in a pre-order method

    if ( root == nullptr ) {
        return;
    }

    // Checks to see if the left child exists
    if ( root->left != nullptr ) {
        dotLines.push_back( "    " + root->data + " -> " + root->left->data + ( root->left->isRed ? "[color=\"red\"]\n" : "[color=\"black\"]\n" ) );
    }

    // Checks to see if the right child exists
    if ( root->right != nullptr ) {
        dotLines.push_back( "    " + root->data + " -> " + root->right->data + ( root->right->isRed ? "[color=\"red\"]\n" : "[color=\"black\"]\n" ) );
    }

    // Continues pre-order search
    this->TraverseDigraph ( root->left, dotLines );
    this->TraverseDigraph ( root->right, dotLines );

}


// --------------------------------------------------------------------------------------
// Function that will go through the tree in a postorder formation and delete every node
// --------------------------------------------------------------------------------------
void Tree::deleteTree ( Node* root ) {

    if ( root == nullptr ) {

        return;

    }

    this->postorder( root->left );
    this->postorder( root->right );
    delete this->root;

    return;
}
