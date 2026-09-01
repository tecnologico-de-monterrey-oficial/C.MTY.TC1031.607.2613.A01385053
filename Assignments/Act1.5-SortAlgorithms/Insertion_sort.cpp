//David Gil Alvarado
//A01385053

#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> datos = {12, 11, 13, 5, 6};
    insertionSort(datos);

    for (int x : datos) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}