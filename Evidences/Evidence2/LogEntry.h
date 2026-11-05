#ifndef LOG_ENTRY_H
#define LOG_ENTRY_H

#include <string>

struct LogEntry {
    std::string mes;
    int dia;
    int anio;
    std::string hora;
    std::string ip;
    std::string mensaje;
    long long timestampNumerico;

    bool operator<(const LogEntry& other) const {
        return timestampNumerico < other.timestampNumerico;
    }
    bool operator>(const LogEntry& other) const {
        return timestampNumerico > other.timestampNumerico;
    }
    bool operator==(const LogEntry& other) const {
        return timestampNumerico == other.timestampNumerico;
    }
};

#endif