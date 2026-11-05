#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;
    Node(T d) : data(d), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void addFirst(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addLast(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insert(int index, T data) {
        if (index < 0 || index > size) throw std::out_of_range("Out Of Range");
        if (index == 0) {
            addFirst(data);
            return;
        }
        if (index == size) {
            addLast(data);
            return;
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) current = current->next;
        Node<T>* newNode = new Node<T>(data);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }

    bool deleteData(T data) {
        Node<T>* current = head;
        while (current) {
            if (current->data == data) {
                if (current == head) {
                    head = head->next;
                    if (head) head->prev = nullptr;
                    else tail = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    if (tail) tail->next = nullptr;
                    else head = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool deleteAt(int index) {
        if (index < 0 || index >= size) return false;
        Node<T>* current = head;
        for (int i = 0; i < index; i++) current = current->next;
        if (current == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } else if (current == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        size--;
        return true;
    }

    T getData(int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Out Of Range");
        Node<T>* current = head;
        for (int i = 0; i < index; i++) current = current->next;
        return current->data;
    }

    void updateData(T target, T newData) {
        Node<T>* current = head;
        bool found = false;
        while (current) {
            if (current->data == target) {
                current->data = newData;
                found = true;
                break;
            }
            current = current->next;
        }
        if (!found) throw std::out_of_range("Out Of Range");
    }

    void updateAt(int index, T newData) {
        if (index < 0 || index >= size) throw std::out_of_range("Out Of Range");
        Node<T>* current = head;
        for (int i = 0; i < index; i++) current = current->next;
        current->data = newData;
    }

    int findData(T data) {
        Node<T>* current = head;
        int index = 0;
        while (current) {
            if (current->data == data) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Out Of Range");
        Node<T>* current = head;
        for (int i = 0; i < index; i++) current = current->next;
        return current->data;
    }

    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other) {
        if (this != &other) {
            clear();
            Node<T>* current = other.head;
            while (current) {
                addLast(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        size = 0;
    }

    void sort() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node<T>* current = head;
            while (current->next) {
                if (current->data > current->next->data) {
                    T temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

    void duplicate() {
        Node<T>* current = head;
        while (current) {
            Node<T>* newNode = new Node<T>(current->data);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) {
                current->next->prev = newNode;
            } else {
                tail = newNode;
            }
            current->next = newNode;
            current = newNode->next;
            size++;
        }
    }

    void removeDuplicates() {
        if (!head) return;
        Node<T>* current = head;
        while (current) {
            Node<T>* runner = current->next;
            while (runner) {
                if (runner->data == current->data) {
                    Node<T>* duplicateNode = runner;
                    runner = runner->next;
                    if (duplicateNode->next) duplicateNode->next->prev = duplicateNode->prev;
                    else tail = duplicateNode->prev;
                    if (duplicateNode->prev) duplicateNode->prev->next = duplicateNode->next;
                    delete duplicateNode;
                    size--;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

void displayMenu() {
    std::cout << "\n--- MENU ---\n";
    std::cout << "1. Inicializar lista (aleatorios)\n";
    std::cout << "2. Inicializar lista (captura manual)\n";
    std::cout << "3. Agregar al inicio (addFirst)\n";
    std::cout << "4. Agregar al final (addLast)\n";
    std::cout << "5. Insertar en posicion (insert)\n";
    std::cout << "6. Borrar por dato (deleteData)\n";
    std::cout << "7. Borrar por posicion (deleteAt)\n";
    std::cout << "8. Obtener dato por posicion (getData)\n";
    std::cout << "9. Actualizar dato (updateData)\n";
    std::cout << "10. Actualizar por posicion (updateAt)\n";
    std::cout << "11. Buscar dato (findData)\n";
    std::cout << "12. Limpiar lista (clear)\n";
    std::cout << "13. Ordenar lista (sort)\n";
    std::cout << "14. Duplicar elementos (duplicate)\n";
    std::cout << "15. Remover duplicados (removeDuplicates)\n";
    std::cout << "16. Imprimir lista\n";
    std::cout << "17. Salir\n";
    std::cout << "Selecciona una opcion: ";
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    DoublyLinkedList<int> list;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    list.clear();
                    int n;
                    std::cout << "Cantidad de datos a generar: ";
                    std::cin >> n;
                    for (int i = 0; i < n; i++) {
                        list.addLast(rand() % 100);
                    }
                    std::cout << "Lista inicializada con datos aleatorios.\n";
                    break;
                }
                case 2: {
                    list.clear();
                    int n, val;
                    std::cout << "Cantidad de datos a capturar: ";
                    std::cin >> n;
                    for (int i = 0; i < n; i++) {
                        std::cout << "Dato " << i + 1 << ": ";
                        std::cin >> val;
                        list.addLast(val);
                    }
                    break;
                }
                case 3: {
                    int val;
                    std::cout << "Ingresa el dato: ";
                    std::cin >> val;
                    list.addFirst(val);
                    break;
                }
                case 4: {
                    int val;
                    std::cout << "Ingresa el dato: ";
                    std::cin >> val;
                    list.addLast(val);
                    break;
                }
                case 5: {
                    int index, val;
                    std::cout << "Ingresa la posicion: ";
                    std::cin >> index;
                    std::cout << "Ingresa el dato: ";
                    std::cin >> val;
                    list.insert(index, val);
                    break;
                }
                case 6: {
                    int val;
                    std::cout << "Ingresa el dato a borrar: ";
                    std::cin >> val;
                    if (list.deleteData(val)) {
                        std::cout << "Dato borrado.\n";
                    } else {
                        std::cout << "Dato no encontrado.\n";
                    }
                    break;
                }
                case 7: {
                    int index;
                    std::cout << "Ingresa la posicion a borrar: ";
                    std::cin >> index;
                    if (list.deleteAt(index)) {
                        std::cout << "Posicion borrada.\n";
                    } else {
                        std::cout << "Posicion invalida.\n";
                    }
                    break;
                }
                case 8: {
                    int index;
                    std::cout << "Ingresa la posicion: ";
                    std::cin >> index;
                    std::cout << "Dato en la posicion " << index << ": " << list.getData(index) << "\n";
                    break;
                }
                case 9: {
                    int target, newData;
                    std::cout << "Dato a actualizar: ";
                    std::cin >> target;
                    std::cout << "Nuevo dato: ";
                    std::cin >> newData;
                    list.updateData(target, newData);
                    std::cout << "Dato actualizado.\n";
                    break;
                }
                case 10: {
                    int index, newData;
                    std::cout << "Posicion a actualizar: ";
                    std::cin >> index;
                    std::cout << "Nuevo dato: ";
                    std::cin >> newData;
                    list.updateAt(index, newData);
                    std::cout << "Posicion actualizada.\n";
                    break;
                }
                case 11: {
                    int val;
                    std::cout << "Ingresa el dato a buscar: ";
                    std::cin >> val;
                    int pos = list.findData(val);
                    if (pos != -1) {
                        std::cout << "Dato encontrado en el indice " << pos << ".\n";
                    } else {
                        std::cout << "Dato no encontrado.\n";
                    }
                    break;
                }
                case 12: {
                    list.clear();
                    std::cout << "Lista vaciada.\n";
                    break;
                }
                case 13: {
                    list.sort();
                    std::cout << "Lista ordenada.\n";
                    break;
                }
                case 14: {
                    list.duplicate();
                    std::cout << "Elementos duplicados.\n";
                    break;
                }
                case 15: {
                    list.removeDuplicates();
                    std::cout << "Duplicados removidos.\n";
                    break;
                }
                case 16: {
                    std::cout << "Contenido de la lista: ";
                    list.print();
                    break;
                }
                case 17: {
                    std::cout << "Finalizando ejecucion.\n";
                    break;
                }
                default:
                    std::cout << "Opcion no valida.\n";
            }
        } catch (const std::out_of_range& e) {
            std::cout << "Error atrapado: " << e.what() << "\n";
        }

    } while (choice != 17);

    return 0;
}