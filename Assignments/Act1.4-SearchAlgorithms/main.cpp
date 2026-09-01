// David Gil Alvarado
// A01385053

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int busquedaSecuencial(vector<int> vec, int valor) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == valor) {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(vector<int> vec, int valor) {
    int inicio = 0;
    int fin = vec.size() - 1;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        if (vec[medio] == valor) {
            return medio;
        }
        if (vec[medio] < valor) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

int main() {
    srand(time(0));

    vector<int> numeros(10000);
    for (int i = 0; i < 10000; i++) {
        numeros[i] = rand() % 1000000 + 1;
    }

    sort(numeros.begin(), numeros.end());

    int objetivo;
    do {
        cout << "Ingresa un numero entre 1 y 1,000,000 (0 para salir): ";
        cin >> objetivo;

        if (objetivo != 0) {
            clock_t t1_sec = clock();
            int idx_sec = busquedaSecuencial(numeros, objetivo);
            clock_t t2_sec = clock();
            double tiempo_sec = (double)(t2_sec - t1_sec) / CLOCKS_PER_SEC;

            clock_t t1_bin = clock();
            int idx_bin = busquedaBinaria(numeros, objetivo);
            clock_t t2_bin = clock();
            double tiempo_bin = (double)(t2_bin - t1_bin) / CLOCKS_PER_SEC;

            if (idx_sec != -1) {
                cout << "El numero SI se encuentra en la lista." << endl;
            } else {
                cout << "El numero NO se encuentra en la lista." << endl;
            }

            cout << "Tiempo busqueda secuencial: " << tiempo_sec << " segundos" << endl;
            cout << "Tiempo busqueda binaria: " << tiempo_bin << " segundos" << endl << endl;
        }
    } while (objetivo != 0);

    return 0;
}