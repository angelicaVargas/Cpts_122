/*
* Name: Angelica Vargas
* Date: 4/25/2022
* Project: Binary Search Tree
* Description: Implement a templated binary search tree with an
* implementation that inserts, removes, searches and rebalances.
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class BaseException {

public:
    BaseException(string msg) : message(msg) {}

    string getMessage() {
        return message;
    }

private:
    string message;
};

class NotFoundException : public BaseException {

public:
    NotFoundException(string msg) : BaseException(msg) {}
};

class CompareException : public BaseException {

public:
    CompareException(string msg) : BaseException(msg) {}
};

class InvalidRotateException : public BaseException {

public:
    InvalidRotateException(string msg) : BaseException(msg) {}
};

template <typename T>
class BSTree {
private:
    class Node {
public:
        Node();
        ~Node();
        Node* left;
        Node* right;
        Node* up;
        T item;
};

    Node* root;
    int (*Compare)(T, T);
    void InsertRecursive(Node* itemPtr, T item);
    void RemoveRecursive(Node* itemPtr, T item);
    T SearchRecursive(Node* itemPtr, T item);
    void RotateLeft(Node* node);
    void RotateRight(Node* node);

public:
    BSTree(int (*Compare)(T, T));
    ~BSTree();
    void Insert(T item);
    void Remove(T item);
    T Search(T item);
    void Rebalance();
};

template <typename T>
BSTree<T>::Node::Node() {

    left = 0;
    right = 0;
    up = 0;
    item = 0;
}

template <typename T>
BSTree<T>::Node::~Node() {}

template <typename T>
BSTree<T>::BSTree(int (*Compare)(T, T)) {

    root = 0;

    this->Compare = Compare;
}

template <typename T>
BSTree<T>::~BSTree() {

    delete root;
}

template <typename T>
int BinaryCompare(T item1, T item2) {

    if (item1 > item2)
        return -1;

    else if (item1 == item2)
        return 0;

    else if (item1 < item2)
        return 1;

    else
        throw CompareException("Error, Compare failure");
}

template <typename T>
void BSTree<T>::Insert(T item) {

    InsertRecursive(root, item);
}

template <typename T>
void BSTree<T>::InsertRecursive(Node* itemPtr, T item) {

    if (root == 0) {

        root = new Node;
        root->up = 0;
        root->item = item;
    }
    else if (Compare(itemPtr->item, item) == -1) {

        if (itemPtr->left == 0) {

            itemPtr->left = new Node;
            itemPtr->left->up = itemPtr;
            itemPtr->left->item = item;
        }
        else
            InsertRecursive(itemPtr->left, item);
    }
    else if (Compare(itemPtr->item, item) == 1) {

        if (itemPtr->right == 0) {

            itemPtr->right = new Node;
            itemPtr->right->up = itemPtr;
            itemPtr->right->item = item;
        }
        else
            InsertRecursive(itemPtr->right, item);
    }
    else if (Compare(itemPtr->item, item) == 0)
        throw CompareException("Duplicate value");
    else
        throw CompareException("Error, Insertion failure");
}

template <typename T>
void BSTree<T>::Remove(T item) {

    RemoveRecursive(root, item);
}

template <typename T>
void BSTree<T>::RemoveRecursive(Node* itemPtr, T item) {

    if (itemPtr == 0)
        throw NotFoundException("Error, Item not found");

    else if (Compare(itemPtr->item, item) == -1)
        RemoveRecursive(itemPtr->left, item);

    else if (Compare(itemPtr->item, item) == 1)
        RemoveRecursive(itemPtr->right, item);

    else if (Compare(itemPtr->item, item) == 0 && itemPtr->up->left != 0 && Compare(itemPtr->up->left->item, item) == 0 && itemPtr->left == 0 && itemPtr->right == 0) //left leaf case
    {
        itemPtr->up->left = 0;
        delete itemPtr;
    }
    else if (Compare(itemPtr->item, item) == 0 && itemPtr->up->right != 0 && Compare(itemPtr->up->right->item, item) == 0 && itemPtr->left == 0 && itemPtr->right == 0) //right leaf case
    {
        itemPtr->up->right = 0;
        delete itemPtr;
    }
    else if (Compare(itemPtr->item, item) == 0 && itemPtr->up->left != 0 && Compare(itemPtr->up->left->item, item) == 0 && itemPtr->left != 0 && itemPtr->right == 0) //left leaf case, one child left
    {
        itemPtr->up->left = itemPtr->left;
        itemPtr->left->up = itemPtr->up;
        delete itemPtr;
    }
    else if (Compare(itemPtr->item, item) == 0 && itemPtr->up->left != 0 && Compare(itemPtr->up->left->item, item) == 0 && itemPtr->left == 0 && itemPtr->right != 0) //left leaf case, one child right
    {
        itemPtr->up->left = itemPtr->right;
        itemPtr->right->up = itemPtr->up;
        delete itemPtr;
    }
    else if (Compare(itemPtr->item, item) == 0 && itemPtr->up->right != 0 && Compare(itemPtr->up->right->item, item) == 0 && itemPtr->left != 0 && itemPtr->right == 0) //right leaf case, one child left
    {
        itemPtr->up->right = itemPtr->left;
        itemPtr->left->up = itemPtr->up;
        delete itemPtr;
    }
    else if (Compare(itemPtr->item, item) == 0 && itemPtr->up->left != 0 && Compare(itemPtr->up->left->item, item) == 0 && itemPtr->left == 0 && itemPtr->right != 0) //left leaf case, one child right
    {
        itemPtr->up->right = itemPtr->right;
        itemPtr->right->up = itemPtr->up;
        delete itemPtr;
    }
    else if (Compare(itemPtr->item, item) == 0 && itemPtr->up->left != 0 && Compare(itemPtr->up->left->item, item) == 0 && itemPtr->left != 0 && itemPtr->right != 0) //left case with two children
    {
        Node* newPtr = itemPtr->left;
        while (newPtr->right != 0) {

            newPtr = newPtr->right;
        }
        if (itemPtr->left == newPtr) {

            newPtr->up = itemPtr->up;
            newPtr->right = itemPtr->right;
            newPtr->up->left = newPtr;
            newPtr->right->up = newPtr;
            delete itemPtr;
        }
        else if (newPtr->left != 0) {

            newPtr->up->right = 0;
            newPtr->up = itemPtr->up;
            newPtr->right = itemPtr->right;
            newPtr->up->left = newPtr;
            newPtr->right->up = newPtr;
            Node* newPtr2 = newPtr->left;

            while (newPtr2->left != 0) {

                newPtr2 = newPtr2->left;
            }
            newPtr2->left = itemPtr->left;
            newPtr2->left->up = newPtr2;
            delete itemPtr;
        }
    }
    else if (Compare(itemPtr->item, item) == 0 && itemPtr->up->right != 0 && Compare(itemPtr->up->right->item, item) == 0 && itemPtr->left != 0 && itemPtr->right != 0) //right case with two children
    {
        Node* newPtr = itemPtr->left;
        while (newPtr->right != 0) {

            newPtr = newPtr->right;
        }
        if (itemPtr->left == newPtr) {

            newPtr->up = itemPtr->up;
            newPtr->right = itemPtr->right;
            newPtr->up->right = newPtr;
            newPtr->right->up = newPtr;
            delete itemPtr;
        }
        else if (newPtr->left != 0) {

            newPtr->up->right = 0;
            newPtr->up = itemPtr->up;
            newPtr->right = itemPtr->right;
            newPtr->up->right = newPtr;
            newPtr->right->up = newPtr;
            Node* newPtr2 = newPtr->left;
            while (newPtr2->left != 0) {

                newPtr2 = newPtr2->left;
            }
            newPtr2->left = itemPtr->left;
            newPtr2->left->up = newPtr2;
            delete itemPtr;
        }
    }
    else
        throw NotFoundException("Error, Item not found");
}

template <typename T>
T BSTree<T>::Search(T item) {
    return SearchRecursive(root, item);
}

template <typename T>
T BSTree<T>::SearchRecursive(Node* itemPtr, T item) {

    if (itemPtr != 0 && Compare(itemPtr->item, item) == -1)
        SearchRecursive(itemPtr->left, item);

    else if (itemPtr != 0 && Compare(itemPtr->item, item) == 1)
        SearchRecursive(itemPtr->right, item);

    else if (itemPtr != 0 && Compare(itemPtr->item, item) == 0)
        return itemPtr->item;

    else
        throw NotFoundException("Error, Item not found");
}

template <typename T>
void BSTree<T>::RotateLeft(Node* node) {

    if (node == 0 || node->right == 0)
        throw InvalidRotateException("Error, Invalid rotate target");

    T tempItem = node->item;
    node->item = node->right->item;
    node->right->item = tempItem;
    Node* rightNode = node->right;
    node->right = rightNode->right;
    rightNode->right = rightNode->left;
    rightNode->left = node->left;
    node->left = rightNode;

    if (node->right != 0)
        node->right->up = node;

    if (rightNode->left != 0)
        rightNode->left->up = node;
}

template <typename T>
void BSTree<T>::RotateRight(Node* node) {

    if (node == 0 || node->left == 0)
        throw InvalidRotateException("Error, Invalid rotate target");

    T tempItem = node->item;
    node->item = node->left->item;
    node->left->item = tempItem;
    Node* leftNode = node->left;
    node->left = leftNode->left;
    leftNode->left = leftNode->right;
    leftNode->right = node->right;
    node->right = leftNode;

    if (node->left != 0)
        node->left->up = node;

    if (leftNode->right != 0)
        leftNode->right->up = node;
}

template <typename T>
void BSTree<T>::Rebalance() {

    Node* node = root;
    int size = 0;
    int total = 0;
    while (node != 0) {

        while (node->left != 0) {

            RotateRight(node);
        }
        node = node->right;
        size++;
    }
    total = ceil(log2(size));
    node = root;
    for (int i = 0; i < total; i++) {

        if (i == 0) {
            RotateLeft(node);
            node = root;
        }
        else {
            RotateLeft(node->right);
            node = node->right;
        }
    }

    int count = total;
    while (count > 1) {
        count /= 2;
        RotateLeft(root);
        node = root;

        for (int i = 0; i < count - 1; i++) {
            RotateLeft(node->right);
            node = node->right;
        }
    }
}

int main() {

    return 0;
}

