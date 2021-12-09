#include "Node.h"

#include <string>
#include <vector>

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

class Tree {

    private:

        // Variables
        Node* root;

        // Functions
        Node* Insert ( std::string data, Node* root );

        Node* rotateLeft ( Node* root );
        Node* rotateRight ( Node* root );
        bool color ( Node* root );

        bool SearchFor ( std::string key, Node* root );
        int Count ( Node* root, std::string key );
        int height ( Node* root );

        void preorder ( Node* root );
        void inorder ( Node* root );
        void postorder ( Node* root );

        void deleteTree ( Node* root );

    public:

        // Constructors
        Tree();
        ~Tree();
        Tree( Node* root );

        // Functions
        void Insert ( std::string data );
        bool Search ( std::string data );
        int Count ( std::string data );
        int height ();

        void generateDigraph ( std::string fileName );
        void TraverseDigraph ( Node* root, std::vector<std::string> &dotLines );

};
