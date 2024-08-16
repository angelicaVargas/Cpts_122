#pragma once
#include <ostream>
using namespace std;

template <typename T>
class ADTStack
{
public:
    virtual void push(T& item) = 0;
    virtual void pop() = 0;
    virtual T peek() = 0;
    virtual int size() = 0;
    virtual void displayStack(ostream& stream) = 0;
};