#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
#include "DoubleNode.h"

template <typename T>
class DoublyLinkedList {
private:
    DoubleNode<T>* head;
    DoubleNode<T>* tail;
    int sizeCount;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), sizeCount(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    bool isEmpty() const { return sizeCount == 0; }
    int size() const { return sizeCount; }

    void addLast(T val) {
        DoubleNode<T>* newNode = new DoubleNode<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        sizeCount++;
    }

    void clear() {
        DoubleNode<T>* current = head;
        while (current) {
            DoubleNode<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        sizeCount = 0;
    }

    DoubleNode<T>* getHead() const { return head; }
    DoubleNode<T>* getTail() const { return tail; }
};

#endif