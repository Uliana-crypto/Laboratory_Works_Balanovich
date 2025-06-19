#include "Header.h"
int main()
{
    int32_t size{};
    double* array{};
    int32_t choice{};
    int32_t sortChoice{};
    int32_t orderChoice{};
    bool ascending{};

    std::cout << "Select an option:\n"
        << "1 - Read array from file and display on console\n"
        << "2 - Enter array from console and save to file\n"
        << "3 - Read array from file and save to file\n"
        << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1  choice == 2  choice == 3)
    {
        std::cout << "Choose sorting method:\n"
            << "1 - Quick Sort\n"
            << "2 - Insertion Sort\n"
            << "3 - Selection Sort\n"
            << "4 - Merge Sort\n"
            << "5 - Optimized Bubble Sort\n"
            << "6 - QSort (descending based on decimal places)\n"
            << "Enter your choice: ";
        std::cin >> sortChoice;

        std::cout << "Sort order:\n"
            << "1 - Ascending\n"
            << "2 - Descending\n"
            << "Enter order: ";
        std::cin >> orderChoice;

        ascending = (orderChoice == 1);
    }

    switch (choice)
    {
    case 1:
        array = readFromFile("data.txt", size);
        if (array)
        {
            switch (sortChoice)
            {
            case 1: quickSort(array, 0, size - 1, ascending);
            break;
            case 2: insertionSort(array, size, ascending); 
            break;
            case 3: selectionSort(array, size, ascending); 
            break;
            case 4: mergeSort(array, 0, size - 1, ascending);
            break;
            case 5: bubbleSortOptimized(array, size, ascending); 
            break;
            case 6: qsortDescending(array, size);
            break;
            }
            std::cout << "Processed array: ";
            OutputArray(std::cout, array, size);
            delete[] array;
        }
        break;

    case 2:
        array = readFromConsole(size);
        switch (sortChoice) 
        {
        case 1: quickSort(array, 0, size - 1, ascending);
        break;
        case 2: insertionSort(array, size, ascending); 
        break;
        case 3: selectionSort(array, size, ascending); 
        break;
        case 4: mergeSort(array, 0, size - 1, ascending);
        break;
        case 5: bubbleSortOptimized(array, size, ascending); 
        break;
        case 6: qsortDescending(array, size); 
        break;
        }
        writeToFile("data.txt", array, size);
        delete[] array;
        break;

    case 3:
        array = readFromFile("data.txt", size);
        if (array) 
        {
            switch (sortChoice) 
            {
            case 1: quickSort(array, 0, size - 1, ascending); 
            break;
            case 2: insertionSort(array, size, ascending); 
            break;
            case 3: selectionSort(array, size, ascending);
            break;
            case 4: mergeSort(array, 0, size - 1, ascending);
            break;
            case 5: bubbleSortOptimized(array, size, ascending);
            break;
            case 6: qsortDescending(array, size); 
            break;
            }
            writeToFile("data.txt", array, size);
            delete[] array;
        }
        break;

    default:
        std::cout << "Invalid choice. Please try again.\n";
    }
    std::cout << "Enter number of students: ";
    std::cin >> size;
    std::cin.ignore();

    Student* students = new Student[size];

    InputAllStudents(students, size);

    SortByAverageGrade(students, size);

    std::cout << "\nSorted students by average grade:\n";
    OutputAllStudents(students, size);

    delete[] students;
    return 0;
}