#include "header.h"
using namespace std;

void CreateMatrix(int32_t**& matrix, int32_t rows)
{
 matrix = new int32_t * [rows];
 for (int32_t i = 0; i < rows; ++i)
 {
  matrix[i] = new int32_t[rows];
 }
}

void InputArraySize(int32_t& rows)
{
 std::cout << "Input Rows(cols)\n";
 std::cin >> rows;
 if (std::cin.fail()  rows <= 0  rows > 100)
 {
  throw std::invalid_argument("Size must be between 1 and 99");
 }
}

// Функция поиска максимального элемента в столбцах без положительных чисел
void FindMaxInNonPositiveColumns(int32_t** matrix, int32_t size) 
{
 int32_t count{};
 for (int32_t j = 0; j < size; ++j) 
 {
  int32_t maxInColumn = matrix[0][j];
  bool hasPositive = false;
  for (int32_t i = 0; i < size; ++i)
  {
   if (matrix[i][j] > 0) {
    hasPositive = true;
   }
   if (matrix[i][j] > maxInColumn)
   {
    maxInColumn = matrix[i][j];
   }
  }
  if (!hasPositive) 
  {
   std::cout << "Maximum values in columns without positive numbers:\n";
   std::cout << maxInColumn << std::endl;
   count++;
  }
 }
 if (count == 0)
 {
  std::cout << "No columns found without positive numbers\n";
 }
 
}

// Функция вычисления сумм диагоналей, параллельных главной
void FindDiagonalSums(int32_t** matrix, int32_t rows)
{
 std::cout << "Diagonal sums parallel to main:\n";

 for (int32_t k = 1; k < rows; ++k) 
 {
  int32_t sumAbove{};
  int32_t sumBelow{};

  for (int32_t i = 0, j = k; j < rows; ++i, ++j)
  {
   sumAbove += matrix[i][j];   
   sumBelow += matrix[j][i];  
  }

  std::cout << "Above main diagonal " << k << ": " << sumAbove << "\n";
  std::cout << "Below main diagonal " << k << ": " << sumBelow << "\n";
 }
}

// Функция поиска первой строки без отрицательных элементов
int32_t FindFirstNonNegativeRow(int32_t** matrix, int32_t size)
{
 for (int32_t i = 0; i < size; ++i) 
 {
  int32_t negativeCount = 0; 
  for (int32_t j = 0; j < size; ++j)
  {
   if (matrix[i][j] < 0)
   {
    negativeCount++;
    break; 
   }
  }
  if (negativeCount == 0) 
  {
   return i+1;
  }
 }
 return -1;
}

// Функция подсчёта отрицательных элементов в нижнем правом треугольнике
int32_t CountNegativesInLowerRightTriangle(int32_t** matrix, int32_t size) 
{
 int32_t count{};

 for (int32_t i = 0; i < size; ++i)
 {
  for (int32_t j = i; j < size; ++j)
  { 
   if (matrix[i][j] < 0)
   {
    count++;
   }
  }
 }
 if (count == 0) 
 {
  std::cout << "No negative numbers found in the lower right triangle\n";
 }
 return count;
}

void FillArrayFromKeyboard(int32_t**& matrix, int32_t rows)
{
 std::cout << "Enter the array elements: ";
 for (int32_t i = 0; i < rows; ++i)
 {
  for (int32_t j = 0; j < rows; ++j)
  {
   std::cin >> matrix[i][j];
  }
  if (std::cin.fail())
  {
   throw std::invalid_argument("\nIncorrect array element input");
  }
 }
}

void FillArrayRandomly(int32_t**& matrix, int32_t rows, int32_t a, int32_t b)
{
 if (a > b || a == b)
 {
  throw std::invalid_argument("\nThe lower limit of the range must be less than or equal to the upper limit");
 }
 srand((time(nullptr)));
 for (int32_t i = 0; i < rows; ++i)
 {
  for (int32_t j = 0; j < rows; ++j)
  {
   matrix[i][j] = rand() % (b - a + 1) + a;
  }
 }
}

void PrintMatrix(int32_t** matrix, int32_t rows)
{
 for (int32_t i = 0; i < rows; ++i)
 {
  for (int32_t j = 0; j < rows; ++j)
  {
   std::cout << setw(4) << matrix[i][j];
  }
  std::cout << endl;
 }
}

void DeleteMatrixRows(int32_t**& matrix, int32_t rows)
{
 for (int32_t i = 0; i < rows; ++i)
 {
  delete[] matrix[i];
 }
 delete[] matrix;
 matrix = nullptr;
}