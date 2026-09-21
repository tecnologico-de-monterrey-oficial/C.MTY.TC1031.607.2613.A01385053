#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <cstdint>

struct Registro {
    std::string mes;
    int dia;
    int anio;
    int horas;
    int minutos;
    int segundos;
    std::string ip;
    std::string razon;
    int64_t timestamp;
    std::string lineaOriginal;

    bool operator<(const Registro& otro) const {
        return timestamp < otro.timestamp;
    }

    bool operator<=(const Registro& otro) const {
        return timestamp <= otro.timestamp;
    }

    bool operator>(const Registro& otro) const {
        return timestamp > otro.timestamp;
    }

    bool operator>=(const Registro& otro) const {
        return timestamp >= otro.timestamp;
    }

    bool operator==(const Registro& otro) const {
        return timestamp == otro.timestamp;
    }
};

int mesANumero(const std::string& mes);
int64_t parseFechaHora(const std::string& mes, int dia, int anio, int h, int m, int s);
bool parseLineaLog(const std::string& linea, Registro& reg);

#endif