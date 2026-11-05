//David Gil Alvarado
//A01385053

#include <iostream>
#include "BST.h"

int main() {
    BST<int> arbol;
    int opcion;

    do {
        std::cout << "\n--- MENU BST ---\n";
        std::cout << "1. Insertar valores\n";
        std::cout << "2. Borrar un valor\n";
        std::cout << "3. Buscar un valor\n";
        std::cout << "4. Mostrar el arbol\n";
        std::cout << "5. Mostrar recorridos (visit)\n";
        std::cout << "6. Mostrar la altura\n";
        std::cout << "7. Mostrar ancestros\n";
        std::cout << "8. Consultar nivel (whatLevelAmI)\n";
        std::cout << "9. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int val;
                std::cout << "Valor a insertar: ";
                std::cin >> val;
                arbol.insert(val);
                break;
            }
            case 2: {
                int val;
                std::cout << "Valor a borrar: ";
                std::cin >> val;
                arbol.remove(val);
                break;
            }
            case 3: {
                int val;
                std::cout << "Valor a buscar: ";
                std::cin >> val;
                if (arbol.find(val)) std::cout << "SI esta en el arbol.\n";
                else std::cout << "NO esta en el arbol.\n";
                break;
            }
            case 4: {
                std::cout << "Arbol (InOrder): ";
                arbol.print();
                break;
            }
            case 5: {
                int tipo;
                std::cout << "1.Preorder 2.Inorder 3.Postorder 4.Level order: ";
                std::cin >> tipo;
                arbol.visit(tipo);
                break;
            }
            case 6: {
                std::cout << "Altura: " << arbol.height() << "\n";
                break;
            }
            case 7: {
                int val;
                std::cout << "Valor: ";
                std::cin >> val;
                std::cout << "Ancestros: ";
                arbol.ancestors(val);
                break;
            }
            case 8: {
                int val;
                std::cout << "Valor: ";
                std::cin >> val;
                std::cout << "Nivel: " << arbol.whatLevelAmI(val) << "\n";
                break;
            }
            case 9:
                break;
        }
    } while (opcion != 9);

    return 0;
}