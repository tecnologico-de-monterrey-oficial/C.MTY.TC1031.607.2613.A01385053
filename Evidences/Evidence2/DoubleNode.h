#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

template <typename T>
class DoubleNode {
public:
    T data;
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode(T d) : data(d), next(nullptr), prev(nullptr) {}
};

#endif