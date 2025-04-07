#include "header.h"
#include <iostream>

int main()
{

    int32_t* arr = nullptr;
    int32_t size = {};

    try
    {
      
        InputArraySize(size);
        CreateArray(size, arr);
        std::cout << "Select the method of filling the array:\n1. From the keyboard\n2. Random numbers\nYour choice:";

        int32_t choice = 0;
        std::cin >> choice;

        if (choice == 1)
        {
            FillArrayFromKeyboard(arr, size);
        }
        else if (choice == 2)
        {
            int32_t a = 0, b = 0;
            std::cout << "Enter the range of numbers a and b: ";
            std::cin >> a >> b;
            FillArrayRandomly(arr, size, a, b);
        }
        else
        {
            throw std::invalid_argument("Incorrect choice of array filling method");
        }

    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << "\n";
    }

    int32_t product = CalculateProductOfEvenIndices(arr, size);
    std::cout << product << "\n";

    try
    {
        int32_t sum = CalculateSumBetweenZeros(arr, size);
        std::cout << sum << "\n";
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << "\n";
    }

    TransformArray(arr, size);
    std::cout << "\nThe array after moving the negative elements to the beginning:\n";
    PrintArray(arr, size);

    SwapMaxMinByAbs(arr, size);
    std::cout << "\nArray after permutation of maximum and minimum by modulus:\n";
    PrintArray(arr, size);

    try
    {
        int32_t sum = SumAfterLastMinByAbs(arr, size);
        std::cout << "\nSum of elements after the last minimum by modulus: " << sum << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    ReplaceNegativesWithSquares(arr, size);
    std::cout << "\nThe array after replacing negative elements with their squares:\n";
    PrintArray(arr, size);

    SortArray(arr, size);
    std::cout << "\nArray after sorting:\n";
    PrintArray(arr, size);

    DeleteArray(arr);

    return 0;
}