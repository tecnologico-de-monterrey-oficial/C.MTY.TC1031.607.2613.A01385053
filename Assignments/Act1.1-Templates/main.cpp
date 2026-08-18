#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {
    string a = "hola ";
    string b = "crayola";
    cout << "Sum of " << a << " and " << b << " is: " << sum(a, b) << "\n";
    
    int c = 5;
    int d = 10;
    cout << "Sum of " << c << " and " << d << " is: " << sum(c, d) << "\n";
    
    double e = 5.5;
    double f = 10.5;
    cout << "Sum of " << e << " and " << f << " is: " << sum(e, f) << "\n\n";

    Lista<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.print();
    cout << "\n";

    cout << "Tamano: " << list.getSize() << "\n";
    cout << "Maximo: " << list.getMax() << "\n";
    cout << "Dato en pos 0: " << list.getData(0) << "\n\n";

    list.insertAt(1, 25);
    list.print();
    cout << "\n";

    list.removeAt(2);
    list.print();
    cout << "\n";

    list.removeLast();
    list.print();
    cout << "\n";

    Lista<string> things;
    things.insert("Laptop");
    things.insert("bottle");
    things.print();
    cout << "\n";
    
    things.insertAt(1, "mouse");
    things.print();
    cout << "\n";

    return 0;
}