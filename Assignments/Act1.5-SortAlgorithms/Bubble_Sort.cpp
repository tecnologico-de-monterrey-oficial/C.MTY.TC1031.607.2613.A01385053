//David Gil Alvarado
//A01385053

#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    std::vector<int> numeros = {15, 7, 3, 9, 12, 5, 2};
    bubbleSort(numeros);

    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}