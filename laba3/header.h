#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <cmath>

void CreateMatrix(int32_t**&, int32_t);
void DeleteMatrixRows(int32_t**&, int32_t);
void InputArraySize(int32_t&);
void FillArrayFromKeyboard(int32_t**&, int32_t);
void FillArrayRandomly(int32_t**&, int32_t, int32_t, int32_t);
void FindMaxInNonPositiveColumns(int32_t**, int32_t);
void FindDiagonalSums(int32_t**, int32_t);
int32_t FindFirstNonNegativeRow(int32_t**, int32_t);
int32_t CountNegativesInLowerRightTriangle(int32_t**, int32_t);
void PrintMatrix(int32_t**, int32_t);

#endif // HEADER_H