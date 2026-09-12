#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

long long comp = 0;
long long swp = 0;

template <typename T>
void swapSort(vector<T> &v) {
    comp = 0; swp = 0;
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (v[j] < v[i]) {
                T t = v[i]; v[i] = v[j]; v[j] = t;
                swp++;
            }
        }
    }
}

template <typename T>
void selectionSort(vector<T> &v) {
    comp = 0; swp = 0;
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (v[j] < v[m]) m = j;
        }
        if (m != i) {
            T t = v[i]; v[i] = v[m]; v[m] = t;
            swp++;
        }
    }
}

template <typename T>
void bubbleSort(vector<T> &v) {
    comp = 0; swp = 0;
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (v[j + 1] < v[j]) {
                T t = v[j]; v[j] = v[j + 1]; v[j + 1] = t;
                swp++;
            }
        }
    }
}

template <typename T>
void insertionSort(vector<T> &v) {
    comp = 0; swp = 0;
    int n = v.size();
    for (int i = 1; i < n; i++) {
        T k = v[i];
        int j = i - 1;
        while (j >= 0) {
            comp++;
            if (v[j] > k) {
                v[j + 1] = v[j];
                swp++;
                j--;
            } else {
                break;
            }
        }
        v[j + 1] = k;
    }
}

template <typename T>
void mergeAux(vector<T> &v, int l, int m, int r) {
    vector<T> izq(v.begin() + l, v.begin() + m + 1);
    vector<T> der(v.begin() + m + 1, v.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)izq.size() && j < (int)der.size()) {
        if (izq[i] <= der[j]) v[k++] = izq[i++];
        else v[k++] = der[j++];
    }
    while (i < (int)izq.size()) v[k++] = izq[i++];
    while (j < (int)der.size()) v[k++] = der[j++];
}

template <typename T>
void mergeHelper(vector<T> &v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeHelper(v, l, m);
        mergeHelper(v, m + 1, r);
        mergeAux(v, l, m, r);
    }
}

template <typename T>
void mergeSort(vector<T> &v) {
    if (!v.empty()) mergeHelper(v, 0, v.size() - 1);
}

template <typename T>
int partitionAux(vector<T> &v, int l, int r) {
    T p = v[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (v[j] < p) {
            i++;
            T t = v[i]; v[i] = v[j]; v[j] = t;
        }
    }
    T t = v[i + 1]; v[i + 1] = v[r]; v[r] = t;
    return i + 1;
}

template <typename T>
void quickHelper(vector<T> &v, int l, int r) {
    if (l < r) {
        int pi = partitionAux(v, l, r);
        quickHelper(v, l, pi - 1);
        quickHelper(v, pi + 1, r);
    }
}

template <typename T>
void quickSort(vector<T> &v) {
    if (!v.empty()) quickHelper(v, 0, v.size() - 1);
}

template <typename T>
void shellSort(vector<T> &v) {
    int n = v.size();
    for (int g = n / 2; g > 0; g /= 2) {
        for (int i = g; i < n; i++) {
            T t = v[i];
            int j;
            for (j = i; j >= g && v[j - g] > t; j -= g) {
                v[j] = v[j - g];
            }
            v[j] = t;
        }
    }
}

template <typename T>
vector<T> generar(int n, int tipo) {
    vector<T> v(n);
    mt19937 gen(1337);
    if (tipo == 1) {
        uniform_int_distribution<int> d(-10000, 10000);
        for (int i = 0; i < n; i++) v[i] = d(gen);
    } else if (tipo == 2) {
        uniform_real_distribution<float> d(-1000.0f, 1000.0f);
        for (int i = 0; i < n; i++) v[i] = d(gen);
    } else if (tipo == 3) {
        uniform_int_distribution<int> d(65, 90);
        for (int i = 0; i < n; i++) v[i] = (char)d(gen);
    }
    return v;
}

template <typename T>
void mostrar(const vector<T> &v) {
    int n = v.size();
    for (int i = 0; i < min(n, 20); i++) cout << v[i] << " ";
    if (n > 20) cout << "...";
    cout << "\n";
}

template <typename Func, typename T>
long long medir(Func f, vector<T> v) {
    auto t1 = high_resolution_clock::now();
    f(v);
    auto t2 = high_resolution_clock::now();
    return duration_cast<nanoseconds>(t2 - t1).count();
}

template <typename T>
void registrar(string alg, void (*f)(vector<T>&), string tnom, int tid, ostream &out) {
    vector<int> n = {1000, 10000, 100000};
    out << alg << ", " << tnom;
    for (int s : n) {
        vector<T> v = generar<T>(s, tid);
        long long t = medir(f, v);
        out << ", " << t;
    }
    out << "\n";
}

void reporte() {
    ofstream f("tiempos.csv");
    string enc = "algoritmo, tipo de dato, tiempo1000, tiempo10000, tiempo100000\n";
    cout << enc;
    f << enc;

    auto procesar = [&](string tnom, int tid) {
        if (tid == 1) {
            registrar<int>("Swap sort", swapSort<int>, tnom, tid, cout);
            registrar<int>("Swap sort", swapSort<int>, tnom, tid, f);
            registrar<int>("Bubble sort", bubbleSort<int>, tnom, tid, cout);
            registrar<int>("Bubble sort", bubbleSort<int>, tnom, tid, f);
            registrar<int>("Selection Sort", selectionSort<int>, tnom, tid, cout);
            registrar<int>("Selection Sort", selectionSort<int>, tnom, tid, f);
            registrar<int>("Insertion Sort", insertionSort<int>, tnom, tid, cout);
            registrar<int>("Insertion Sort", insertionSort<int>, tnom, tid, f);
            registrar<int>("Merge Sort", mergeSort<int>, tnom, tid, cout);
            registrar<int>("Merge Sort", mergeSort<int>, tnom, tid, f);
            registrar<int>("Quick Sort", quickSort<int>, tnom, tid, cout);
            registrar<int>("Quick Sort", quickSort<int>, tnom, tid, f);
            registrar<int>("Shell sort", shellSort<int>, tnom, tid, cout);
            registrar<int>("Shell sort", shellSort<int>, tnom, tid, f);
        } else if (tid == 2) {
            registrar<float>("Swap sort", swapSort<float>, tnom, tid, cout);
            registrar<float>("Swap sort", swapSort<float>, tnom, tid, f);
            registrar<float>("Bubble sort", bubbleSort<float>, tnom, tid, cout);
            registrar<float>("Bubble sort", bubbleSort<float>, tnom, tid, f);
            registrar<float>("Selection Sort", selectionSort<float>, tnom, tid, cout);
            registrar<float>("Selection Sort", selectionSort<float>, tnom, tid, f);
            registrar<float>("Insertion Sort", insertionSort<float>, tnom, tid, cout);
            registrar<float>("Insertion Sort", insertionSort<float>, tnom, tid, f);
            registrar<float>("Merge Sort", mergeSort<float>, tnom, tid, cout);
            registrar<float>("Merge Sort", mergeSort<float>, tnom, tid, f);
            registrar<float>("Quick Sort", quickSort<float>, tnom, tid, cout);
            registrar<float>("Quick Sort", quickSort<float>, tnom, tid, f);
            registrar<float>("Shell sort", shellSort<float>, tnom, tid, cout);
            registrar<float>("Shell sort", shellSort<float>, tnom, tid, f);
        } else if (tid == 3) {
            registrar<char>("Swap sort", swapSort<char>, tnom, tid, cout);
            registrar<char>("Swap sort", swapSort<char>, tnom, tid, f);
            registrar<char>("Bubble sort", bubbleSort<char>, tnom, tid, cout);
            registrar<char>("Bubble sort", bubbleSort<char>, tnom, tid, f);
            registrar<char>("Selection Sort", selectionSort<char>, tnom, tid, cout);
            registrar<char>("Selection Sort", selectionSort<char>, tnom, tid, f);
            registrar<char>("Insertion Sort", insertionSort<char>, tnom, tid, cout);
            registrar<char>("Insertion Sort", insertionSort<char>, tnom, tid, f);
            registrar<char>("Merge Sort", mergeSort<char>, tnom, tid, cout);
            registrar<char>("Merge Sort", mergeSort<char>, tnom, tid, f);
            registrar<char>("Quick Sort", quickSort<char>, tnom, tid, cout);
            registrar<char>("Quick Sort", quickSort<char>, tnom, tid, f);
            registrar<char>("Shell sort", shellSort<char>, tnom, tid, cout);
            registrar<char>("Shell sort", shellSort<char>, tnom, tid, f);
        }
    };

    procesar("int", 1);
    procesar("float", 2);
    procesar("char", 3);
    f.close();
}

template <typename T>
void probar(vector<T> &v, int a) {
    cout << "Original:\n";
    mostrar(v);

    comp = 0; swp = 0;
    auto t1 = high_resolution_clock::now();

    if (a == 1) swapSort(v);
    else if (a == 2) selectionSort(v);
    else if (a == 3) bubbleSort(v);
    else if (a == 4) insertionSort(v);
    else if (a == 5) mergeSort(v);
    else if (a == 6) quickSort(v);
    else if (a == 7) shellSort(v);

    auto t2 = high_resolution_clock::now();
    long long ns = duration_cast<nanoseconds>(t2 - t1).count();

    cout << "Ordenado:\n";
    mostrar(v);

    cout << "Tiempo: " << ns << " ns\n";
    if (a <= 4) {
        cout << "Comparaciones: " << comp << "\n";
        cout << "Intercambios: " << swp << "\n";
    }
}

int main() {
    int op = 0;
    while (op != 3) {
        cout << "\n1. Probar un algoritmo individual\n2. Generar reporte comparativo (CSV)\n3. Salir\nOpcion: ";
        cin >> op;

        if (op == 1) {
            int t, s, a;
            cout << "Tipo (1.int, 2.float, 3.char): "; cin >> t;
            cout << "Tamano (1.1000, 2.10000, 3.100000): "; cin >> s;
            cout << "Algoritmo (1.Swap, 2.Sel, 3.Bub, 4.Ins, 5.Merge, 6.Quick, 7.Shell): "; cin >> a;

            int n = (s == 1) ? 1000 : ((s == 2) ? 10000 : 100000);

            if (t == 1) { vector<int> v = generar<int>(n, 1); probar(v, a); }
            else if (t == 2) { vector<float> v = generar<float>(n, 2); probar(v, a); }
            else if (t == 3) { vector<char> v = generar<char>(n, 3); probar(v, a); }
        } else if (op == 2) {
            reporte();
        }
    }
    return 0;
}