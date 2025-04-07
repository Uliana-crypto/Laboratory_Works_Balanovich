#ifndef HEADER_H
#define HEADER_H

#include "array_operations.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void CreateArray(int32_t, int32_t*&);
void DeleteArray(int32_t*&);
void InputArraySize(int32_t&);
void FillArrayFromKeyboard(int32_t*, int32_t);
void FillArrayRandomly(int32_t*, int32_t, int32_t, int32_t);
void PrintArray(int32_t*, int32_t);
int32_t CalculateSumBetweenZeros(int32_t*, int32_t);
void FindZeros(int32_t*, int32_t, int32_t&, int32_t&);
void CheckForZeroErrors(int32_t, int32_t);
int32_t CalculateProductOfEvenIndices(int32_t*, int32_t);
void TransformArray(int32_t*, int32_t);
void SwapMaxMinByAbs(int32_t*, int32_t);
void ReplaceNegativesWithSquares(int32_t*, int32_t);
int32_t SumAfterLastMinByAbs(int32_t*, int32_t);
void SortArray(int32_t*, int32_t);

#endif // HEADER_H