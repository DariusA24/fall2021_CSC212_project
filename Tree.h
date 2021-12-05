#include "Node.h"

#include <string>
#include <cstring>

class Tree {

    private:

        // Variables
        Node* root;

        // Functions
        Node* Insert ( std::string data, Node* root );

        Node* rotateLeft ( Node* root );
        Node* rotateRight ( Node* root );
        bool color ( Node* root );

        bool SearchFor ( std::string data, Node* root );
        int Count ( Node* root, std::string key );

        int height ( Node* root );
        void preorder ( Node* root );
        void inorder ( Node* root );
        void postorder ( Node* root );

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

        void generateDOT ();

};
