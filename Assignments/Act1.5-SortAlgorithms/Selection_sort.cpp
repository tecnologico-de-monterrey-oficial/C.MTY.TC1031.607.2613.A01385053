//David Gil Alvarado
//A01385053

#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            std::swap(arr[i], arr[minIdx]);
        }
    }
}

int main() {
    std::vector<int> datos = {29, 10, 14, 37, 13};
    selectionSort(datos);

    for (int x : datos) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}