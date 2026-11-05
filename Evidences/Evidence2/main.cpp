//David Gil Alvarado
//A01385053

#include <iostream>
#include <string>
#include "LogProcessor.h"

int main() {
    LogProcessor processor;
    int opcion;

    do {
        std::cout << "\n========================================\n";
        std::cout << "     EVIDENCIA 2 - PROCESADOR DE LOGS   \n";
        std::cout << "========================================\n";
        std::cout << "1. Cargar archivo de logs (log607-1.txt o log607-2.txt)\n";
        std::cout << "2. Ordenar por fecha y hora\n";
        std::cout << "3. Buscar logs por dia\n";
        std::cout << "4. Mostrar logs por IP (Orden descendente)\n";
        std::cout << "5. Mostrar estadisticas del archivo\n";
        std::cout << "6. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int archivoOpcion;
                std::cout << "Elige el archivo a cargar:\n";
                std::cout << "1. log607-1.txt\n";
                std::cout << "2. log607-2.txt\n";
                std::cout << "Opcion: ";
                std::cin >> archivoOpcion;

                if (archivoOpcion == 1) {
                    processor.cargarArchivo("log607-1.txt");
                } else if (archivoOpcion == 2) {
                    processor.cargarArchivo("log607-2.txt");
                } else {
                    std::cout << "Opcion no valida.\n";
                }
                break;
            }
            case 2: {
                processor.ordenarLogs();
                break;
            }
            case 3: {
                std::string mes;
                int dia, anio;
                std::cout << "Ingresa el mes (ej. May, Jun, Sep): ";
                std::cin >> mes;
                std::cout << "Ingresa el dia: ";
                std::cin >> dia;
                std::cout << "Ingresa el anio: ";
                std::cin >> anio;
                processor.buscarPorFecha(mes, dia, anio);
                break;
            }
            case 4: {
                std::string ip;
                std::cout << "Ingresa la direccion IP a buscar: ";
                std::cin >> ip;
                processor.mostrarPorIP(ip);
                break;
            }
            case 5: {
                processor.mostrarEstadisticas();
                break;
            }
            case 6:
                std::cout << "Finalizando programa...\n";
                break;
            default:
                std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);

    return 0;
}