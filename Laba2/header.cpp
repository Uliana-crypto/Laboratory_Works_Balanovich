#include "header.h"

void InputArraySize(int32_t& size)
{
    std::cout << "Input Size\n";
    std::cin >> size;
    if (std::cin.fail()  size <= 0  size > 100)
    {
        throw std::invalid_argument("Size must be between 1 and 99");
    }
}

void FillArrayFromKeyboard(int32_t* arr, int32_t size)
{
    std::cout << "Enter the array elements: ";
    for (int32_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
        if (std::cin.fail())
        {
            throw std::invalid_argument("\nIncorrect array element input");
        }
    }
}

void FillArrayRandomly(int32_t* arr, int32_t size, int32_t a, int32_t b)
{
    if (a > b)
    {
        throw std::invalid_argument("\nThe lower limit of the range must be less than or equal to the upper limit");
    }
    srand((time(nullptr)));
    for (int32_t i = 0; i < size; ++i)
    {
        arr[i] = rand() % (b - a + 1) + a;
    }
}

void PrintArray(int32_t* arr, int32_t size)
{
    for (int32_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

void CreateArray(int32_t size, int32_t*& arr)
{
    arr = new int32_t[size];
}

void DeleteArray(int32_t*& arr)
{
    delete[]arr;
}

int32_t CalculateProductOfEvenIndices(int32_t* arr, int32_t size)
{
    int32_t product = 1;

    for (int32_t i = 0; i < size; ++i)
    {
        if (i % 2 == 0) 
        {
            product *= arr[i]; 
        }
    }
    std::cout << "\nProduct of array elements with even numbers: ";
    return product; 
}

void FindZeros(int32_t* arr, int32_t size, int32_t& firstZero, int32_t& lastZero)
{
    for (int32_t i = 0; i < size; ++i)
    {
        if (arr[i] == 0)
        {
            firstZero = i; 
            break;
        }
    }
    for (int32_t i = size - 1; i >= 0; --i)
    {
        if (arr[i] == 0)
        {
            lastZero = i;
            break;
        }
    }
}

int32_t CalculateSumBetweenZeros(int32_t* arr, int32_t size)
{
    int32_t firstZero = 0;
    int32_t lastZero = 0;
    int32_t sum = 0;
    FindZeros(arr, size, firstZero, lastZero);
    CheckForZeroErrors(firstZero, lastZero);
    for (int32_t numb = firstZero + 1; numb < lastZero; ++numb)
    {
        sum += numb;
    }
    std::cout << "\nThe length of array elements between zero elements: ";
    return sum;
}

void CheckForZeroErrors(int32_t firstZero, int32_t lastZero)
{
    if (firstZero == -1 || lastZero == -2)
    {
        throw std::runtime_error("\nThere are no null elements in the array.");
    }
    if (firstZero == lastZero - 1)
    {
        throw std::runtime_error("\nThere are no elements to calculate between the first and last zeros.");
    }
}

void TransformArray(int32_t* arr, int32_t size)
{
    for (int32_t i = 0; i < size - 1; ++i)
    {
        for (int32_t j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] >= 0 && arr[j + 1] < 0)
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void SwapMaxMinByAbs(int32_t* arr, int32_t size)
{
    int32_t maxIndex{};
    int32_t minIndex{};

    for (int32_t i = 1; i < size; ++i)
    {
        if (std::abs(arr[i]) > std::abs(arr[maxIndex]))
        {
            maxIndex = i;
        }
        if (std::abs(arr[i]) < std::abs(arr[minIndex]))
        {
            minIndex = i;
        }
    }
    std::swap(arr[maxIndex], arr[minIndex]);
}

void ReplaceNegativesWithSquares(int32_t* arr, int32_t size)
{
    for (int32_t i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
        {
            arr[i] = arr[i] * arr[i];
        }
    }
}

int32_t SumAfterLastMinByAbs(int32_t* arr, int32_t size)
{
    int32_t lastMinIndex = 0;
    for (int32_t i = 1; i < size; ++i)
    {
        if (std::abs(arr[i]) <= std::abs(arr[lastMinIndex]))
        {
            lastMinIndex = i;
        }
    }
    if (lastMinIndex == size - 1) 
    {
        throw std::runtime_error("\nThere are no elements after the last minimum element");
    }
    int32_t sum{};
    for (int32_t i = lastMinIndex + 1; i < size; ++i)
    {
        sum += arr[i];
    }

    return sum;
}

void SortArray(int32_t* arr, int32_t size)
{
    for (int32_t i{}; i < size - 1; ++i)
        {
        for (int32_t j{}; j < size - 1 - i; ++j)
            {
              if (arr[j] > arr[j + 1])
              {
                 int32_t temp = arr[j];
                 arr[j] = arr[j + 1];
                 arr[j + 1] = temp;
              }
            }
        }
}