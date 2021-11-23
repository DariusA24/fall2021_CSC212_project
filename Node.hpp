#pragma once

class Node {

    private:

        int data;
        bool isRed;
        Node* leftLeg;
        Node* rightLeg;

        Node* Insert ( int data, bool isRed );

        friend class BSTree;

    public:

        Node();
        ~Node();
        Node( int data );

};
