#include <string>

class Node {

    private:

        std::string data;
        bool isRed;
        Node* left;
        Node* right;

        void changeColor ();

        friend class Tree;

    public:

        Node();
        ~Node();
        Node( std::string data );

};
