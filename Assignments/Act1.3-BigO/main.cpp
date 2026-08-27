//David Gil Alvarado
//A01385053

#include <vector>

int sumaImparesIterativa(const std::vector<int>& arr) {
    int suma = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 != 0) {
            suma += arr[i];
        }
    }
    return suma;
}

int sumaImparesRecursiva(const std::vector<int>& arr, int i = 0) {
    if (i >= arr.size()) {
        return 0;
    }
    
    int actual = (arr[i] % 2 != 0) ? arr[i] : 0;
    return actual + sumaImparesRecursiva(arr, i + 1);
}