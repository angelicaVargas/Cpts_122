#pragma once
#include <iostream>

using namespace std;

class IntDLLNode
{
public:
    IntDLLNode(int data);

    int data;
    IntDLLNode* prev;
    IntDLLNode* next;
};

IntDLLNode::IntDLLNode(int data) : data(data)
{
    prev = nullptr;
    next = nullptr;
}

void swap(IntDLLNode* first, IntDLLNode* second) {

    IntDLLNode* temp;
    temp = first->next;
    first->next = second->next;
    second->next = temp;

    if (first->next != NULL)
        first->next->prev = first;
    if (second->next != NULL)
        second->next->prev = second;

    temp = first->prev;
    first->prev = second->prev;
    second->prev = temp;

    if (first->prev != NULL)
        first->prev->next = first;
    if (second->prev != NULL)
        second->prev->next = second;
}

//continous loop?
//    IntDLLNode* firstPrev = first->prev;
//    IntDLLNode* firstNext = first->next;
//    IntDLLNode* secondPrev = second->prev;
//    IntDLLNode* secondNext = second->next;
//    IntDLLNode* temp;
//
//    temp = firstNext;
//    firstNext = secondNext;
//    secondNext = temp;
//
//    if (firstNext != NULL)
//        firstNext->prev = first;
//    if (secondNext != NULL)
//        secondNext->prev = second;
//
//    temp = firstPrev;
//    firstPrev = secondPrev;
//    secondPrev = temp;
//
//    if (firstPrev != NULL)
//        firstPrev->next = first;
//    if (secondPrev != NULL)
//        secondPrev->next = second;
//}


void insert(IntDLLNode* current, IntDLLNode* newNode, bool insertAfter = false) {

    if (insertAfter == false) {
        //insert an element before root
        if (current->prev == NULL) {
            current->prev = newNode;
            newNode->next = current;
            newNode->prev = NULL;
        }
        else {
            //insert an element before current (false)
            newNode->prev = current->prev; //current's "previous" is now newNode's "previous" (making connection)
            current->prev->next = newNode; //newNode's value is now current's "next"
            newNode->next = current; //current's value is now newNode's "next"
            current->prev = newNode; //newNode's value is now current"s "prev"
        }
    }
    else {
        //insert an element in the end
        if(current->next == NULL) {
            current->next = newNode;
            newNode->next = NULL;
            current = newNode;
        }
        else {
            //insert an element after current (true)
            newNode->next = current->next;
            current->next->prev = newNode;
            newNode->prev = current;
            current->next = newNode;
        }
    }
}

void printList(IntDLLNode* node) {

    while (node->prev != NULL) {
        node = node->prev;
    }

    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

