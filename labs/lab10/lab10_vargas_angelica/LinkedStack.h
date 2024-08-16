#pragma once
#include <stdexcept>
using namespace std;

#include "ADTStack.h"

class StackEmptyException : public runtime_error
{
public:
    StackEmptyException() : runtime_error("Invalid Operation: Stack Empty!") { }

};


template <typename T>
class LinkedStack : public ADTStack<T>
{
private:
    class Node
    {
    public:
        Node() { next = nullptr; }
        T data;
        Node* next;
    };
    int count;
    Node* top;

    void displayStack(Node* node, ostream& stream);

public:
    LinkedStack();
    ~LinkedStack();

    void push(T& item);
    void pop();
    T peek();
    int size();
    void displayStack(ostream& stream);
};


template <typename T>
LinkedStack<T>::LinkedStack()
{
    count = 0;
    top = nullptr;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    while (top)
        pop();
}


template <typename T>
void LinkedStack<T>::push(T& item)
{
    Node* node = new Node(); // do I not neeed *iteam

    node->data = item;
    node->next = top; // new node will psuhed before top

    top = node; // the new node is now top

    count++;
    // TODO: Implement the push method
}

template <typename T>
void LinkedStack<T>::pop()
{
    if (top == nullptr || count == 0)
    {
        throw StackEmptyException();
    }
    Node* temp = top;

    top = top->next;

    delete temp;

    count--;
    // TODO: Implement the pop method
}

template <typename T>
T LinkedStack<T>::peek()
{
    if (!top)
    {
        throw StackEmptyException();
    }
    return top->data;
}

template <typename T>
int LinkedStack<T>::size()
{
    return count;
}

template <typename T>
void LinkedStack<T>::displayStack(ostream& stream)
{
    //stream << "|" << endl;
    stream << "|";
    displayStack(top, stream);
    stream << endl;
    //stream << "|" << endl;
}

template <typename T>
void LinkedStack<T>::displayStack(Node* node, ostream& stream)
{
    if (!node)
        return;

    displayStack(node->next, stream);

    stream << node->data << " ";
}