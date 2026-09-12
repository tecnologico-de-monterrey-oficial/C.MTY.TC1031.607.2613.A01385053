//David Gil Alvarado
//A01385053

#include <iostream>
#include <vector>

template <typename T>
void swap(std::vector<T>& list, int i, int j) {
    T temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

template <typename T>
int getPivot(std::vector<T>& list, int left, int right) {
    int aux = left - 1;
    T pivot = list[right];
    for (int i = left; i < right; i++) {
        if (list[i] < pivot) {
            aux++;
            swap(list, aux, i);
        }
    }
    aux++;
    swap(list, aux, right);
    return aux;
}

template <typename T>
void quicksort(std::vector<T>& list, int left, int right) {
    if (left < right) {
        int pivot = getPivot(list, left, right);
        quicksort(list, left, pivot - 1);
        quicksort(list, pivot + 1, right);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    quicksort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}