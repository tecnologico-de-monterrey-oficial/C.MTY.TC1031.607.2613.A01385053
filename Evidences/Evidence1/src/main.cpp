#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include "../include/Registro.h"
#include "../include/SortAlgorithms.h"
#include "../include/SearchAlgorithms.h"

std::vector<Registro> leerArchivo(const std::string& ruta) {
    std::vector<Registro> datos;
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir archivo: " << ruta << "\n";
        return datos;
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
        Registro reg;
        if (parseLineaLog(linea, reg)) {
            datos.push_back(reg);
        }
    }
    archivo.close();
    return datos;
}

void guardarEnArchivo(const std::string& ruta, const std::vector<Registro>& datos, int inicio, int fin) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error al exportar a: " << ruta << "\n";
        return;
    }
    for (int i = inicio; i <= fin && i < static_cast<int>(datos.size()); ++i) {
        archivo << datos[i].lineaOriginal << "\n";
    }
    archivo.close();
}

int main() {
    bool continuar = true;
    while (continuar) {
        std::cout << "\n========================================\n";
        std::cout << " SISTEMA DE PROCESAMIENTO DE LOGS\n";
        std::cout << "========================================\n";
        std::cout << "1. log607-1.txt (Desordenado)\n";
        std::cout << "2. log607-2.txt (Casi ordenado)\n";
        std::cout << "Seleccione el archivo: ";
        int opcArchivo;
        std::cin >> opcArchivo;

        std::string archivoSeleccionado = (opcArchivo == 2) ? "data/log607-2.txt" : "data/log607-1.txt";
        std::vector<Registro> datos = leerArchivo(archivoSeleccionado);

        if (datos.empty()) {
            std::cout << "No se pudieron cargar datos.\n";
            continue;
        }

        std::cout << "Total de registros cargados: " << datos.size() << "\n\n";

        std::cout << "Algoritmos disponibles:\n";
        std::cout << "1. Insertion Sort\n";
        std::cout << "2. Merge Sort\n";
        std::cout << "3. Quick Sort\n";
        std::cout << "Seleccione el algoritmo: ";
        int opcAlg;
        std::cin >> opcAlg;

        std::cin.ignore();
        std::cout << "\nIngrese su prediccion cualitativa (rapido/lento y por que): ";
        std::string prediccion;
        std::getline(std::cin, prediccion);

        std::string nombreAlg = "";
        std::string bestCase = "";
        std::string worstCase = "";

        auto start = std::chrono::high_resolution_clock::now();

        if (opcAlg == 1) {
            nombreAlg = "Insertion Sort";
            bestCase = "O(N)";
            worstCase = "O(N^2)";
            insertionSort(datos);
        } else if (opcAlg == 2) {
            nombreAlg = "Merge Sort";
            bestCase = "O(N log N)";
            worstCase = "O(N log N)";
            mergeSort(datos, 0, static_cast<int>(datos.size()) - 1);
        } else {
            nombreAlg = "Quick Sort (Last Pivot)";
            bestCase = "O(N log N)";
            worstCase = "O(N^2)";
            quickSort(datos, 0, static_cast<int>(datos.size()) - 1);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duracion = end - start;

        std::cout << "\n----------------------------------------\n";
        std::cout << "RESULTADOS DEL ORDENAMIENTO\n";
        std::cout << "----------------------------------------\n";
        std::cout << "Algoritmo: " << nombreAlg << "\n";
        std::cout << "Archivo: " << archivoSeleccionado << "\n";
        std::cout << "Tamanio de datos: " << datos.size() << " registros\n";
        std::cout << "Tiempo de ejecucion: " << duracion.count() << " ms\n";
        std::cout << "Complejidad Mejor Caso: " << bestCase << "\n";
        std::cout << "Complejidad Peor Caso:  " << worstCase << "\n";
        std::cout << "Prediccion inicial: " << prediccion << "\n";

        guardarEnArchivo("out/output607.txt", datos, 0, static_cast<int>(datos.size()) - 1);
        std::cout << "Datos ordenados exportados a: out/output607.txt\n";

        std::cout << "\n----------------------------------------\n";
        std::cout << "BUSQUEDA POR RANGO DE FECHAS\n";
        std::cout << "Formato esperado: Mes DD AAAA HH:MM:SS\n";
        std::cout << "Ejemplo: Oct 15 2024 00:00:00\n";
        std::cout << "----------------------------------------\n";

        std::string mInicio, mFin, hInicioStr, hFinStr;
        int dInicio, aInicio, dFin, aFin;

        std::cout << "Inicio (Mes Dia Anio HH:MM:SS): ";
        std::cin >> mInicio >> dInicio >> aInicio >> hInicioStr;
        std::cout << "Fin    (Mes Dia Anio HH:MM:SS): ";
        std::cin >> mFin >> dFin >> aFin >> hFinStr;

        int h1, min1, s1, h2, min2, s2;
        char sep;
        std::stringstream ssH1(hInicioStr);
        std::stringstream ssH2(hFinStr);
        ssH1 >> h1 >> sep >> min1 >> sep >> s1;
        ssH2 >> h2 >> sep >> min2 >> sep >> s2;

        int64_t tsInicio = parseFechaHora(mInicio, dInicio, aInicio, h1, min1, s1);
        int64_t tsFin = parseFechaHora(mFin, dFin, aFin, h2, min2, s2);

        if (tsInicio == -1 || tsFin == -1 || tsInicio > tsFin) {
            std::cout << "Rango invalido o error en formato de fechas.\n";
            guardarEnArchivo("out/range607.txt", datos, 1, 0);
        } else {
            int idxInicio = binarySearchLowerBound(datos, tsInicio);
            int idxFin = binarySearchUpperBound(datos, tsFin);

            if (idxInicio <= idxFin && idxInicio < static_cast<int>(datos.size()) && idxFin >= 0) {
                int totalEncontrados = idxFin - idxInicio + 1;
                std::cout << "\nRegistros encontrados: " << totalEncontrados << "\n";
                int limiteMostrar = std::min(10, totalEncontrados);
                for (int i = idxInicio; i < idxInicio + limiteMostrar; ++i) {
                    std::cout << datos[i].lineaOriginal << "\n";
                }
                if (totalEncontrados > 10) {
                    std::cout << "... y " << (totalEncontrados - 10) << " registros adicionales.\n";
                }
                guardarEnArchivo("out/range607.txt", datos, idxInicio, idxFin);
                std::cout << "Subconjunto exportado a: out/range607.txt\n";
            } else {
                std::cout << "\nNo se encontraron registros en el rango especificado.\n";
                guardarEnArchivo("out/range607.txt", datos, 1, 0);
            }
        }

        std::cout << "\n¿Desea realizar otra corrida? (1: Si, 0: No): ";
        int resp;
        std::cin >> resp;
        if (resp != 1) {
            continuar = false;
        }
    }

    std::cout << "Ejecucion terminada.\n";
    return 0;
}