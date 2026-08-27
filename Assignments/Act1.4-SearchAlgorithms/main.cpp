// David Gil Alvarado
// A01385053
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int seqSearch(vector<int> &list, int data) {
    for (int i=0; i<list.size(); i++) {
        if (list[i] == data) {
            return i;
        }
    }
    throw out_of_range("no se encontró el valor");
}

template <typename T>
int binarySearch(vector<T> &list, T data) {
    int left = 0;
    int right = list.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (data == list[mid]) {
            return mid;
        } else {
            if (data < list[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    throw out_of_range("No se econtró el valor");
}

int main() {
    vector<int> list = {3, 5, 6, 8, 11, 12, 13, 16, 27, 35};
    try {
        int index = binarySearch(list, 14);
        cout << "El valor se encuentra en: " << index << endl;
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
    return 0;
}