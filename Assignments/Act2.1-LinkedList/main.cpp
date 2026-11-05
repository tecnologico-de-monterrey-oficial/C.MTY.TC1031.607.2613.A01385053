//David Gil Alvarado
//A01385053

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    LinkedList(const LinkedList& other) : head(nullptr) {
        *this = other;
    }

    // Sobrecarga operador =
    LinkedList& operator=(const LinkedList& other) {
        if (this == &other) return *this;
        clear();
        if (!other.head) return *this;

        head = new Node<T>(other.head->data);
        Node<T>* current = head;
        Node<T>* otherCurrent = other.head->next;

        while (otherCurrent) {
            current->next = new Node<T>(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        return *this;
    }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // addFirst
    void addFirst(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    // addLast
    void addLast(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // insert
    void insert(int index, T val) {
        if (index < 0) throw std::out_of_range("Indice invalido");
        if (index == 0) {
            addFirst(val);
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index - 1 && temp; i++) {
            temp = temp->next;
        }
        if (!temp) throw std::out_of_range("Indice fuera de rango");
        
        Node<T>* newNode = new Node<T>(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // deleteData (Regresa bool)
    bool deleteData(T val) {
        if (!head) return false;
        if (head->data == val) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node<T>* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next) {
            Node<T>* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    // deleteAt (Regresa bool)
    bool deleteAt(int index) {
        if (index < 0 || !head) return false;
        if (index == 0) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index - 1 && temp->next; i++) {
            temp = temp->next;
        }
        if (temp->next) {
            Node<T>* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    // getData
    T getData(int index) {
        if (index < 0) throw std::out_of_range("Indice invalido");
        Node<T>* temp = head;
        for (int i = 0; i < index && temp; i++) {
            temp = temp->next;
        }
        if (!temp) throw std::out_of_range("Indice fuera de rango");
        return temp->data;
    }

    // updateData (Regresa excepcion si no lo encuentra)
    void updateData(T oldVal, T newVal) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data == oldVal) {
                temp->data = newVal;
                return;
            }
            temp = temp->next;
        }
        throw std::out_of_range("Elemento no encontrado para actualizar");
    }

    // updateAt (Regresa excepcion si indice es invalido)
    void updateAt(int index, T val) {
        if (index < 0) throw std::out_of_range("Indice invalido");
        Node<T>* temp = head;
        for (int i = 0; i < index && temp; i++) {
            temp = temp->next;
        }
        if (!temp) throw std::out_of_range("Indice fuera de rango");
        temp->data = val;
    }

    // findData
    int findData(T val) {
        Node<T>* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == val) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    // Sobrecarga operador [ ]
    T& operator[](int index) {
        if (index < 0) throw std::out_of_range("Indice invalido");
        Node<T>* temp = head;
        for (int i = 0; i < index && temp; i++) {
            temp = temp->next;
        }
        if (!temp) throw std::out_of_range("Indice fuera de rango");
        return temp->data;
    }

    void print() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

template <typename T>
void fillRandom(LinkedList<T>& list, int count);

template <>
void fillRandom<int>(LinkedList<int>& list, int count) {
    for (int i = 0; i < count; i++) {
        list.addLast(rand() % 100);
    }
}

template <>
void fillRandom<std::string>(LinkedList<std::string>& list, int count) {
    for (int i = 0; i < count; i++) {
        std::string s = "";
        s += (char)('A' + rand() % 26);
        s += (char)('a' + rand() % 26);
        list.addLast(s);
    }
}

template <typename T>
void menuLogic(LinkedList<T>& list) {
    int choice;
    T val, oldVal;
    int index;
    LinkedList<T> copyList;
    bool success;

    do {
        std::cout << "\n1. addFirst\n2. addLast\n3. insert (en indice)\n"
                  << "4. deleteData\n5. deleteAt\n6. getData\n"
                  << "7. updateData\n8. updateAt\n9. findData\n"
                  << "10. get / update (operador [])\n"
                  << "11. Duplicar (operador =)\n12. Mostrar lista\n0. Salir\nOpcion: ";
        std::cin >> choice;

        try {
            switch (choice) {
                case 1:
                    std::cout << "Valor: "; std::cin >> val;
                    list.addFirst(val);
                    break;
                case 2:
                    std::cout << "Valor: "; std::cin >> val;
                    list.addLast(val);
                    break;
                case 3:
                    std::cout << "Indice: "; std::cin >> index;
                    std::cout << "Valor: "; std::cin >> val;
                    list.insert(index, val);
                    break;
                case 4:
                    std::cout << "Valor a borrar: "; std::cin >> val;
                    success = list.deleteData(val);
                    std::cout << (success ? "Borrado exitoso.\n" : "Elemento no encontrado.\n");
                    break;
                case 5:
                    std::cout << "Indice a borrar: "; std::cin >> index;
                    success = list.deleteAt(index);
                    std::cout << (success ? "Borrado exitoso.\n" : "Fallo al borrar (indice invalido).\n");
                    break;
                case 6:
                    std::cout << "Indice: "; std::cin >> index;
                    std::cout << "Valor: " << list.getData(index) << "\n";
                    break;
                case 7:
                    std::cout << "Valor viejo: "; std::cin >> oldVal;
                    std::cout << "Valor nuevo: "; std::cin >> val;
                    list.updateData(oldVal, val);
                    std::cout << "Actualizado.\n";
                    break;
                case 8:
                    std::cout << "Indice: "; std::cin >> index;
                    std::cout << "Valor: "; std::cin >> val;
                    list.updateAt(index, val);
                    std::cout << "Actualizado.\n";
                    break;
                case 9:
                    std::cout << "Valor a buscar: "; std::cin >> val;
                    index = list.findData(val);
                    if (index != -1) std::cout << "Encontrado en indice: " << index << "\n";
                    else std::cout << "No se encontro el elemento (-1).\n";
                    break;
                case 10:
                    std::cout << "Indice []: "; std::cin >> index;
                    std::cout << "Valor actual: " << list[index] << "\n";
                    std::cout << "Deseas actualizarlo? (1=Si, 0=No): "; 
                    int up; std::cin >> up;
                    if (up == 1) {
                        std::cout << "Nuevo valor: "; std::cin >> val;
                        list[index] = val;
                        std::cout << "Actualizado.\n";
                    }
                    break;
                case 11:
                    copyList = list;
                    std::cout << "Lista duplicada: ";
                    copyList.print();
                    break;
                case 12:
                    list.print();
                    break;
            }
        } catch (const std::out_of_range& e) {
            std::cout << "Excepcion Out_Of_Range capturada: " << e.what() << "\n";
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    } while (choice != 0);
}

int main() {
    srand(time(0));
    int typeChoice, fillChoice;

    std::cout << "Tipo de lista:\n1. Enteros (int)\n2. Textos (string)\nOpcion: ";
    std::cin >> typeChoice;

    std::cout << "Llenado:\n1. Manual\n2. Aleatorio (5 elementos)\nOpcion: ";
    std::cin >> fillChoice;

    if (typeChoice == 1) {
        LinkedList<int> list;
        if (fillChoice == 2) fillRandom(list, 5);
        menuLogic(list);
    } else {
        LinkedList<std::string> list;
        if (fillChoice == 2) fillRandom(list, 5);
        menuLogic(list);
    }

    return 0;
}