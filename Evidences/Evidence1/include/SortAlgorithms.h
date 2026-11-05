#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include <vector>
#include "Registro.h"

void insertionSort(std::vector<Registro>& arr);
void mergeSort(std::vector<Registro>& arr, int l, int r);
void quickSort(std::vector<Registro>& arr, int low, int high);

#endif