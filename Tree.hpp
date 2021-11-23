#include "node.h"

class Tree {

    private:

        Node* root;

    public:

        Tree();
        ~Tree();
        Tree( Node* root );

        Node* insert ( int data );

        Node* rotateLeft ( Node* root );
        Node* rotateRight ( Node* root );



};
