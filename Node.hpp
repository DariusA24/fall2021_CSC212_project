#pragma once

class Node {

    private:

        int data;
        bool isRed;
        Node* leftLeg;
        Node* rightLeg;

        friend class Tree;

    public:

        Node();
        ~Node();
        Node( int data );

        Node* Insert ( int data, bool isRed );

};
