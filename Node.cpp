#include "node.h"

Node::Node() {

    this->data = 0;
    this->isRed = false;
    this->leftLeg = nullptr;
    this->rightLeg = nullptr;

}

Node::~Node() {

    if ( this->leftLeg != nullptr ) {

        delete this->leftLeg;

    }

    if ( this->rightLeg != nullptr ) {

        delete this->rightLeg;

    }

}

Node::Node ( int data ) {

    this->data = data;
    this->isRed = true;
    this->leftLeg = nullptr;
    this->rightLeg = nullptr;

}

Node* Node::Insert ( int Data, bool isRed ) {



}
