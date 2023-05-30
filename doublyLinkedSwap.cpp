#include "doublyLinkedSwap.h"

void swapWithNext(Node * p){
    Node *n = p->next;
    if((p->value) && (n->value)){
        //both Nodes have values
        p->next = n->next;
        p->next->prev = p;
        n->prev = p->prev;
        n->prev->next = n;
        p->prev = n;
        n->next = p;
    }
}

int main(){
    Node *head = new Node();
    Node *middle = new Node();
    Node *middleTwo = new Node();
    Node *middleThree = new Node();
    Node *middleFour = new Node();
    Node *tail = new Node();

    head->next = middle;
    head->prev = nullptr;

    middle->next = middleTwo;
    middle->prev = head;

    middleTwo->next = middleThree;
    middleTwo->prev = middle;

    middleThree->prev = middleTwo;
    middleThree->next = middleFour;

    middleFour->prev = middleThree;
    middleFour->next = tail;

    middle->value = 1;
    middleTwo->value = 2;
    middleThree->value = 3;
    middleFour->value = 4;


    tail->next = nullptr;
    tail->prev = middleFour;

    printForwards(head);
    printBackwards(tail);

    swapWithNext(middleFour);

    printForwards(head);
    printBackwards(tail);

    }