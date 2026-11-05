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
class Stack {
private:
    Node<T>* head;
    int count;

public:
    Stack() : head(nullptr), count(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return count == 0;
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
        count++;
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("El historial esta vacio");
        }
        Node<T>* temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;
        count--;
        return data;
    }

    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("El historial esta vacio");
        }
        return head->data;
    }

    int size() const {
        return count;
    }
};

struct PaginaWeb {
    std::string url;
    std::string fecha_hora;
};

int main() {
    Stack<PaginaWeb> historial;
    int opcion;

    do {
        std::cout << "\n--- HISTORIAL DE NAVEGACION ---\n";
        std::cout << "1. Visitar una nueva pagina\n";
        std::cout << "2. Retroceder a la pagina anterior\n";
        std::cout << "3. Ver la pagina actual\n";
        std::cout << "4. Mostrar cuantas paginas hay en el historial\n";
        std::cout << "5. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                PaginaWeb pagina;
                std::cout << "Ingresa la URL: ";
                std::cin.ignore();
                std::getline(std::cin, pagina.url);
                std::cout << "Ingresa la fecha y hora: ";
                std::getline(std::cin, pagina.fecha_hora);
                
                historial.push(pagina);
                std::cout << "Pagina agregada al historial.\n";
                break;
            }
            case 2: {
                try {
                    PaginaWeb pagina = historial.pop();
                    std::cout << "Retrocediendo... Se saco la pagina:\n";
                    std::cout << "URL: " << pagina.url << " | Fecha/Hora: " << pagina.fecha_hora << "\n";
                } catch (const std::out_of_range& e) {
                    std::cout << "No hay paginas para retroceder.\n";
                }
                break;
            }
            case 3: {
                try {
                    PaginaWeb pagina = historial.top();
                    std::cout << "Pagina actual:\n";
                    std::cout << "URL: " << pagina.url << " | Fecha/Hora: " << pagina.fecha_hora << "\n";
                } catch (const std::out_of_range& e) {
                    std::cout << "El historial esta vacio.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Paginas en el historial: " << historial.size() << "\n";
                break;
            }
            case 5: {
                std::cout << "Cerrando navegador...\n";
                break;
            }
            default: {
                std::cout << "Opcion no valida.\n";
            }
        }
    } while (opcion != 5);

    return 0;
}