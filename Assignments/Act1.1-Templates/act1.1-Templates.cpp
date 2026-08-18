#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main() {
    List<int> numeros;
    
    numeros.insert(10);
    numeros.insert(20);
    numeros.insert(30);
    numeros.print();
    
    numeros.insertAt(1, 15);
    numeros.print();
    
    numeros.removeAt(2);
    numeros.print();
    
    cout << numeros.getMax() << endl;
    cout << numeros.getSize() << endl;
    cout << numeros.getData(1) << endl;
    
    numeros.removeLast();
    numeros.print();

    List<string> palabras;
    
    palabras.insert("Mundo");
    palabras.insert("C++");
    palabras.print();
    
    palabras.insertAt(0, "Hola");
    palabras.print();
    
    palabras.removeAt(-1);
    
    palabras.removeLast();
    palabras.removeLast();
    palabras.removeLast();
    
    palabras.removeLast();

    return 0;
}