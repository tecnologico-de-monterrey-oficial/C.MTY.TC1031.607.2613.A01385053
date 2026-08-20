//David Gil Alvarado
//A01385053

#include <iostream>

using namespace std;

long long sumIterative(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

long long sumRecursive(int n) {
    if (n <= 0) return 0;
    return n + sumRecursive(n - 1);
}

long long sumFormula(long long n) {
    return (n * (n + 1)) / 2;
}

long long fibonacciIterative(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    long long a = 1, b = 1, c;
    for (int i = 3; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long fibonacciRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

long long bacteriasIterative(int n) {
    long long b = 1;
    for (int i = 1; i <= n; ++i) {
        long long nacimientos = b * 3.78;
        long long fallecimientos = b * 2.34;
        b = b + nacimientos - fallecimientos;
    }
    return b;
}

long long bacteriasRecursive(int n) {
    if (n == 0) return 1;
    long long prev = bacteriasRecursive(n - 1);
    long long nacimientos = prev * 3.78;
    long long fallecimientos = prev * 2.34;
    return prev + nacimientos - fallecimientos;
}

double investmentIterative(double amount, int months) {
    for (int i = 0; i < months; ++i) {
        amount *= 1.1875;
    }
    return amount;
}

double investmentRecursive(double amount, int months) {
    if (months <= 0) return amount;
    return investmentRecursive(amount * 1.1875, months - 1);
}

double powIterative(double n, int y) {
    double result = 1.0;
    for (int i = 0; i < y; ++i) {
        result *= n;
    }
    return result;
}

double powRecursive(double n, int y) {
    if (y == 0) return 1.0;
    return n * powRecursive(n, y - 1);
}

int main() {
    cout << "Suma Iterativa (n=10): " << sumIterative(10) << "\n";
    cout << "Suma Formula (n=10): " << sumFormula(10) << "\n";
    cout << "Fibonacci Recursivo (n=6): " << fibonacciRecursive(6) << "\n";
    cout << "Bacterias Iterativo (n=5 dias): " << bacteriasIterative(5) << "\n";
    cout << "Inversion Iterativa (1000, 3 meses): " << investmentIterative(1000, 3) << "\n";
    cout << "Potencia Iterativa (2^4): " << powIterative(2, 4) << "\n";
    
    return 0;
}