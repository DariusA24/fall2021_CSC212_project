#pragma once

class Node {

    private:

        int data;
        bool isRed;
        Node* left;
        Node* right;

        Node* Insert ( int data );

        void changeColor ( Node* root );

        friend class BSTree;

    public:

        Node();
        ~Node();
        Node( int data );

};
