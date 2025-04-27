#include "header.h"

int main() {
    int32_t rows{};
    int32_t** matrix{};
    int32_t choice{};

    try {
        InputArraySize(rows);
        CreateMatrix(matrix, rows);
        std::cout << "Choose input method:\n1 - Keyboard\n2 - Random numbers\n";
        std::cin >> choice;

        if (choice == 1)
        {
            FillArrayFromKeyboard(matrix, rows);
        }
        else if (choice == 2)
        {
            int32_t minRange{};
            int32_t maxRange{};
            std::cout << "Enter min and max range values: ";
            std::cin >> minRange >> maxRange;
            FillArrayRandomly(matrix, rows, minRange, maxRange);
        }
        else 
        {
            throw std::invalid_argument("Invalid choice! Please select 1 or 2.");
        }
        PrintMatrix(matrix, rows);
        FindDiagonalSums(matrix, rows);
        int32_t firstRow = FindFirstNonNegativeRow(matrix, rows);
        if (firstRow != -1) {
            std::cout << "First row without negative numbers: " << firstRow << "\n";
        }
        else {
            std::cout << "No rows without negative numbers found\n";
        }
        FindMaxInNonPositiveColumns(matrix, rows);
        int32_t negativeCount = CountNegativesInLowerRightTriangle(matrix, rows);
        if (negativeCount > 0) {
            std::cout << "Negative numbers in lower right triangle: ";
            std::cout << negativeCount << "\n";
        }

    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << "\n";
    }
    catch (const std::exception& e) 
    {
        std::cout << e.what() << "\n";
    }
    catch (...)
    {
        std::cout << "Unknown error\n";
    }

    DeleteMatrixRows(matrix, rows);

    return 0;
}