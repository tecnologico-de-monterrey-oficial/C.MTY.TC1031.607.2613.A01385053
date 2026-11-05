#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T d) : data(d), next(nullptr) {}
};

#endif