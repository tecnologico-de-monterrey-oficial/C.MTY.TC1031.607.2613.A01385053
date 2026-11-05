#include "../include/Registro.h"
#include <sstream>
#include <iomanip>

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

int64_t parseFechaHora(const std::string& mes, int dia, int anio, int h, int m, int s) {
    int mNum = mesANumero(mes);
    if (mNum == 0) return -1;
    int64_t ts = anio;
    ts = ts * 100 + mNum;
    ts = ts * 100 + dia;
    ts = ts * 100 + h;
    ts = ts * 100 + m;
    ts = ts * 100 + s;
    return ts;
}

bool parseLineaLog(const std::string& linea, Registro& reg) {
    if (linea.empty()) return false;
    std::stringstream ss(linea);
    std::string horaStr;
    if (!(ss >> reg.mes >> reg.dia >> reg.anio >> horaStr >> reg.ip)) {
        return false;
    }
    std::getline(ss, reg.razon);
    if (!reg.razon.empty() && reg.razon[0] == ' ') {
        reg.razon = reg.razon.substr(1);
    }
    char sep;
    std::stringstream ssHora(horaStr);
    if (!(ssHora >> reg.horas >> sep >> reg.minutos >> sep >> reg.segundos)) {
        return false;
    }
    reg.timestamp = parseFechaHora(reg.mes, reg.dia, reg.anio, reg.horas, reg.minutos, reg.segundos);
    reg.lineaOriginal = linea;
    return (reg.timestamp != -1);
}