#ifndef LOG_PROCESSOR_H
#define LOG_PROCESSOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "LogEntry.h"
#include "DoublyLinkedList.h"

class LogProcessor {
private:
    DoublyLinkedList<LogEntry> listaLogs;
    bool estaOrdenado;

    int mesANumero(const std::string& mes) {
        if (mes == "Jan") return 1;
        if (mes == "Feb") return 2;
        if (mes == "Mar") return 3;
        if (mes == "Apr") return 4;
        if (mes == "May") return 5;
        if (mes == "Jun") return 6;
        if (mes == "Jul") return 7;
        if (mes == "Aug") return 8;
        if (mes == "Sep") return 9;
        if (mes == "Oct") return 10;
        if (mes == "Nov") return 11;
        if (mes == "Dec") return 12;
        return 0;
    }

    long long calcularTimestamp(const std::string& mes, int dia, int anio, const std::string& hora) {
        int m = mesANumero(mes);
        int h = 0, min = 0, s = 0;
        char basura;
        std::stringstream ss(hora);
        ss >> h >> basura >> min >> basura >> s;

        return (long long)anio * 10000000000LL + (long long)m * 100000000LL + (long long)dia * 1000000LL + (long long)h * 10000 + (long long)min * 100 + s;
    }

public:
    LogProcessor() : estaOrdenado(false) {}

    bool cargarArchivo(const std::string& nombreArchivo) {
        std::ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            std::cout << "No se pudo abrir el archivo " << nombreArchivo << "\n";
            return false;
        }

        listaLogs.clear();
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string mes, hora, ip, mensaje;
            int dia, anio;

            if (ss >> mes >> dia >> anio >> hora >> ip) {
                std::getline(ss, mensaje);
                LogEntry entry;
                entry.mes = mes;
                entry.dia = dia;
                entry.anio = anio;
                entry.hora = hora;
                entry.ip = ip;
                entry.mensaje = mensaje;
                entry.timestampNumerico = calcularTimestamp(mes, dia, anio, hora);

                listaLogs.addLast(entry);
            }
        }
        archivo.close();
        estaOrdenado = false;
        std::cout << "Archivo cargado exitosamente. Total de registros: " << listaLogs.size() << "\n";
        return true;
    }

    void ordenarLogs() {
        if (listaLogs.isEmpty()) {
            std::cout << "La lista esta vacia. Carga un archivo primero.\n";
            return;
        }

        std::vector<LogEntry> vec;
        DoubleNode<LogEntry>* current = listaLogs.getHead();
        while (current) {
            vec.push_back(current->data);
            current = current->next;
        }

        auto inicio = std::chrono::high_resolution_clock::now();

        long long comparaciones = 0;
        std::sort(vec.begin(), vec.end(), [&comparaciones](const LogEntry& a, const LogEntry& b) {
            comparaciones++;
            return a.timestampNumerico < b.timestampNumerico;
        });

        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duracion = fin - inicio;

        listaLogs.clear();
        for (const auto& entry : vec) {
            listaLogs.addLast(entry);
        }
        estaOrdenado = true;

        std::ofstream salida("output_sorted.txt");
        current = listaLogs.getHead();
        while (current) {
            salida << current->data.mes << " " << current->data.dia << " " << current->data.anio << " "
                   << current->data.hora << " " << current->data.ip << current->data.mensaje << "\n";
            current = current->next;
        }
        salida.close();

        std::cout << "\n--- REPORTE DE ORDENAMIENTO ---\n";
        std::cout << "Algoritmo utilizado: std::sort\n";
        std::cout << "Tamano de los datos: " << vec.size() << " registros\n";
        std::cout << "Tiempo de ejecucion: " << duracion.count() << " ms\n";
        std::cout << "Numero de comparaciones: " << comparaciones << "\n";
        std::cout << "Archivo generado: output_sorted.txt\n";
    }

    void buscarPorFecha(const std::string& mesBuscado, int diaBuscado, int anioBuscado) {
        if (listaLogs.isEmpty()) {
            std::cout << "No hay registros cargados.\n";
            return;
        }
        if (!estaOrdenado) {
            std::cout << "Aviso: La lista no esta ordenada. Se ordenara automaticamente.\n";
            ordenarLogs();
        }

        DoubleNode<LogEntry>* current = listaLogs.getHead();
        int encontrados = 0;
        bool empezoElDia = false;

        std::cout << "\n--- RESULTADOS PARA " << mesBuscado << " " << diaBuscado << ", " << anioBuscado << " ---\n";
        while (current) {
            if (current->data.mes == mesBuscado && current->data.dia == diaBuscado && current->data.anio == anioBuscado) {
                empezoElDia = true;
                encontrados++;
                std::cout << current->data.hora << " | " << current->data.ip << " | " << current->data.mensaje << "\n";
            } else if (empezoElDia) {
                break;
            }
            current = current->next;
        }

        if (encontrados == 0) {
            std::cout << "No se encontraron registros para la fecha especificada.\n";
        } else {
            std::cout << "Total de registros encontrados: " << encontrados << "\n";
        }
    }

    void mostrarPorIP(const std::string& ipBuscada) {
        if (listaLogs.isEmpty()) {
            std::cout << "No hay registros cargados.\n";
            return;
        }

        DoubleNode<LogEntry>* current = listaLogs.getTail();
        int encontrados = 0;

        std::cout << "\n--- REGISTROS PARA LA IP " << ipBuscada << " (ORDEN DESCENDENTE) ---\n";
        while (current) {
            if (current->data.ip == ipBuscada) {
                encontrados++;
                std::cout << current->data.mes << " " << current->data.dia << " " << current->data.anio << " "
                          << current->data.hora << " | " << current->data.mensaje << "\n";
            }
            current = current->prev;
        }

        if (encontrados == 0) {
            std::cout << "No se encontraron registros para la IP ingresada.\n";
        } else {
            std::cout << "Total encontrados: " << encontrados << "\n";
        }
    }

    void mostrarEstadisticas() {
        if (listaLogs.isEmpty()) {
            std::cout << "No hay registros cargados.\n";
            return;
        }

        std::cout << "\n--- ESTADISTICAS DEL ARCHIVO ---\n";
        std::cout << "Total de registros: " << listaLogs.size() << "\n";
        
        DoubleNode<LogEntry>* head = listaLogs.getHead();
        DoubleNode<LogEntry>* tail = listaLogs.getTail();

        if (head && tail) {
            std::cout << "Fecha inicial: " << head->data.mes << " " << head->data.dia << ", " << head->data.anio << "\n";
            std::cout << "Fecha final: " << tail->data.mes << " " << tail->data.dia << ", " << tail->data.anio << "\n";
        }
    }
};

#endif