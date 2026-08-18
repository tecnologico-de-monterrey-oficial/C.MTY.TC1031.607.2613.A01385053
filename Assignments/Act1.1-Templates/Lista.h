#ifndef LISTA_H
#define LISTA_H

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Lista {
private:
    vector<T> data;
    int size;
public:
    Lista();
    void insert(T val);
    void removeLast();
    T getData(int pos);
    int getSize();
    T getMax();
    void print();
    void insertAt(int pos, T val);
    T removeAt(int pos);
};

template <typename T>
Lista<T>::Lista() {
    size = 0;
}

template <typename T>
void Lista<T>::insert(T val) {
    data.push_back(val);
    size++;
}

template <typename T>
void Lista<T>::removeLast() {
    if (size < 1) {
        cout << "NO HAY ELEMENTOS\n";
        return;
    }
    cout << data.back() << "\n";
    data.pop_back();
    size--;
}

template <typename T>
T Lista<T>::getData(int pos) {
    if (0 <= pos && pos < size) {
        return data.at(pos);
    }
    return T();
}

template <typename T>
int Lista<T>::getSize() {
    return size;
}

template <typename T>
T Lista<T>::getMax() {
    if (size < 1) {
        return T();
    }
    T currMax = data.at(0);
    for (int i = 1; i < size; i++) {
        if (data.at(i) > currMax) {
            currMax = data.at(i);
        }
    }
    return currMax;
}

template <typename T>
void Lista<T>::print() {
    if (size < 1) {
        cout << "NO HAY ELEMENTOS\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] - " << data.at(i) << "\n";
    }
}

template <typename T>
void Lista<T>::insertAt(int pos, T val) {
    if (pos < 0 || pos > size) {
        cout << "POSICIÓN INVÁLIDA\n";
        return;
    }
    data.insert(data.begin() + pos, val);
    size++;
}

template <typename T>
T Lista<T>::removeAt(int pos) {
    if (size < 1) {
        cout << "NO HAY ELEMENTOS\n";
        return T();
    }
    if (pos < 0 || pos >= size) {
        cout << "POSICIÓN INVÁLIDA\n";
        return T();
    }
    T removedElement = data.at(pos);
    cout << removedElement << "\n";
    data.erase(data.begin() + pos);
    size--;
    return removedElement;
}

#endif