#include "Node.h"
#include <string>

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
Node::Node() {

    this->data = "";
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
Node::Node ( std::string data ) {

    // Create node with the data value and make it red
    this->data = data;
    this->isRed = true;

    // Both legs are nullptr, they don't exist yet
    this->left = nullptr;
    this->right = nullptr;

}

// -----------------------------------------
// Function to change color of current Node
// -----------------------------------------
void Node::changeColor ( ) {

    this->isRed = !( this->isRed );

}
