//David Gil Alvarado
//A01385053

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void swapSort(vector<T>&list){
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (list[j] < list[i]) {
                T temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

int main() {

    vector<int> datos = {18, 4, 25, 11, 2, 7};

    cout << "Original: ";
    for (int num : datos) {
        cout << num << " ";
    }
    cout << "\n";

    swapSort(datos);

    cout << "Ordenado: ";
    for (int num : datos) {
        cout << num << " ";
    }
    cout << "\n";

return 0;
}