#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    Node(T d) : data(d), left(nullptr), right(nullptr) {}
};

#endif