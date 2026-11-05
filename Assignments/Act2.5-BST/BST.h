#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>
#include <algorithm>
#include "Node.h"

template <typename T>
class BST {
private:
    Node<T>* root;

    void destroyTree(Node<T>* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    Node<T>* insertRec(Node<T>* node, T val) {
        if (!node) return new Node<T>(val);
        if (val < node->data) node->left = insertRec(node->left, val);
        else if (val > node->data) node->right = insertRec(node->right, val);
        return node;
    }

    Node<T>* findMin(Node<T>* node) {
        while (node && node->left != nullptr) node = node->left;
        return node;
    }

    Node<T>* removeRec(Node<T>* node, T val) {
        if (!node) return node;
        if (val < node->data) {
            node->left = removeRec(node->left, val);
        } else if (val > node->data) {
            node->right = removeRec(node->right, val);
        } else {
            if (!node->left) {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }
            Node<T>* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeRec(node->right, temp->data);
        }
        return node;
    }

    void preOrder(Node<T>* node) const {
        if (!node) return;
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node<T>* node) const {
        if (!node) return;
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node<T>* node) const {
        if (!node) return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }

    void levelOrder(Node<T>* node) const {
        if (!node) return;
        std::queue<Node<T>*> q;
        q.push(node);
        while (!q.empty()) {
            Node<T>* current = q.front();
            q.pop();
            std::cout << current->data << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    int heightRec(Node<T>* node) const {
        if (!node) return 0;
        int leftH = heightRec(node->left);
        int rightH = heightRec(node->right);
        return 1 + std::max(leftH, rightH);
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroyTree(root);
    }

    void insert(T val) {
        root = insertRec(root, val);
    }

    void remove(T val) {
        if (!find(val)) {
            std::cout << "El dato no se encuentra en el arbol.\n";
            return;
        }
        root = removeRec(root, val);
    }

    bool find(T val) const {
        Node<T>* current = root;
        while (current) {
            if (val == current->data) return true;
            else if (val < current->data) current = current->left;
            else current = current->right;
        }
        return false;
    }

    void print() const {
        if (!root) {
            std::cout << "El arbol esta vacio.";
        } else {
            inOrder(root);
        }
        std::cout << "\n";
    }

    void visit(int order) const {
        if (!root) {
            std::cout << "El arbol esta vacio.\n";
            return;
        }
        switch (order) {
            case 1: preOrder(root); break;
            case 2: inOrder(root); break;
            case 3: postOrder(root); break;
            case 4: levelOrder(root); break;
            default: std::cout << "Opcion no valida.";
        }
        std::cout << "\n";
    }

    int height() const {
        return heightRec(root);
    }

    void ancestors(T val) const {
        if (!find(val)) {
            std::cout << "El dato no se encuentra en el arbol.\n";
            return;
        }
        Node<T>* current = root;
        while (current && current->data != val) {
            std::cout << current->data << " ";
            if (val < current->data) current = current->left;
            else current = current->right;
        }
        std::cout << "\n";
    }

    int whatLevelAmI(T val) const {
        Node<T>* current = root;
        int level = 1;
        while (current) {
            if (val == current->data) return level;
            else if (val < current->data) current = current->left;
            else current = current->right;
            level++;
        }
        return -1;
    }
};

#endif