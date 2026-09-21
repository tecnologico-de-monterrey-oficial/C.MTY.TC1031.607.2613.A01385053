#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include <vector>
#include <cstdint>
#include "Registro.h"

int binarySearchLowerBound(const std::vector<Registro>& arr, int64_t targetTimestamp);
int binarySearchUpperBound(const std::vector<Registro>& arr, int64_t targetTimestamp);

#endif