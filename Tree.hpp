#include "Node.hpp"

class Tree {

    private:
    
        // Variables
        Node* root;
    
        // Functions
        Node* Insert ( int data, Node* root );
    
        Node* rotateLeft ( Node* root );
        Node* rotateRight ( Node* root );

    public:

        // Constructors
        Tree();
        ~Tree();
        Tree( Node* root );

        // Functions
        void Insert ( int data );
    
   
};
