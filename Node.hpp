#pragma once

class Node {

    private:

        int data;
        bool isRed;
        Node* left;
        Node* right;

        Node* Insert ( int data );

        void changeColor ( Node* root );

        friend class Tree;

    public:

        Node();
        ~Node();
        Node( int data );

        Node* Node::rotateLeft ( Node* root );
        Node* Node::rotateRight ( Node* root );

        bool SearchFor ( int value, Node* root );

};
