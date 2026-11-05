//David Gil Alvarado
//A01385053

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T d) : data(d), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int count;

public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return count == 0;
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("La fila esta vacia");
        }
        Node<T>* temp = head;
        T data = temp->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        count--;
        return data;
    }

    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("La fila esta vacia");
        }
        return head->data;
    }

    int size() const {
        return count;
    }
};

struct Cliente {
    std::string nombre;
    int boletos;
};

int main() {
    Queue<Cliente> fila;
    int opcion;

    do {
        std::cout << "\n--- MENU TAQUILLA DE BOLETOS ---\n";
        std::cout << "1. Llegada de un nuevo cliente\n";
        std::cout << "2. Atender al siguiente cliente\n";
        std::cout << "3. Mostrar cuantas personas hay en la fila\n";
        std::cout << "4. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                Cliente c;
                std::cout << "Ingresa el nombre del cliente: ";
                std::cin.ignore();
                std::getline(std::cin, c.nombre);
                std::cout << "Ingresa la cantidad de boletos a comprar: ";
                std::cin >> c.boletos;
                
                fila.push(c);
                std::cout << "Cliente agregado a la fila exitosamente.\n";
                break;
            }
            case 2: {
                try {
                    Cliente c = fila.pop();
                    std::cout << "Atendiendo al cliente: " << c.nombre 
                              << " | Boletos solicitados: " << c.boletos << "\n";
                } catch (const std::out_of_range& e) {
                    std::cout << "No hay nadie en la fila para atender.\n";
                }
                break;
            }
            case 3: {
                std::cout << "Hay " << fila.size() << " personas actualmente en la fila.\n";
                break;
            }
            case 4: {
                std::cout << "Cerrando el sistema...\n";
                break;
            }
            default: {
                std::cout << "Opcion no valida. Intenta de nuevo.\n";
            }
        }
    } while (opcion != 4);

    return 0;
}