#ifndef List_h
#define List_h

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class List {
private:
    vector<T> data;
    int size;
public:
    List();
    void insert(T val);
    void removeLast();
    T getData(int pos);
    int getSize();
    T getMax();
    void print();
    void insertAt(int pos, T val);
    void removeAt(int pos);
};

template <typename T>
List<T>::List() {
    size = 0;
}

template <typename T>
void List<T>::insert(T val) {
    data.push_back(val);
    size++;
}

template <typename T>
void List<T>::removeLast() {
    if (size > 0) {
        cout << data[size - 1] << endl;
        data.pop_back();
        size--;
    } else {
        cout << "NO HAY ELEMENTOS" << endl;
    }
}

template <typename T>
T List<T>::getData(int pos) {
    return data[pos];
}

template <typename T>
int List<T>::getSize() {
    return size;
}

template <typename T>
T List<T>::getMax() {
    T max_val = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }
    return max_val;
}

template <typename T>
void List<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] - " << data[i] << endl;
    }
}

template <typename T>
void List<T>::insertAt(int pos, T val) {
    if (pos < 0 || pos > size) {
        cout << "POSICION INVALIDA" << endl;
        return;
    }
    data.insert(data.begin() + pos, val);
    size++;
}

template <typename T>
void List<T>::removeAt(int pos) {
    if (size == 0) {
        cout << "NO HAY ELEMENTOS" << endl;
        return;
    }
    if (pos < 0 || pos >= size) {
        cout << "POSICION INVALIDA" << endl;
        return;
    }
    
    T val = data[pos];
    data.erase(data.begin() + pos);
    size--;
    cout << val << endl;
}

#endif