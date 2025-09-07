#include "operations.h"
#include "sort.h"

template<typename T>
void performSort(T* arr, int32_t size, int32_t sortChoice, char direction)
{
    auto start = std::chrono::high_resolution_clock::now();
    switch (sortChoice) 
    {
    case 1:
        bubbleSort(arr, size, direction);
        break;
    case 2:
        shakerSort(arr, size, direction);
        break;
    case 3: 
        combSort(arr, size, direction);
        break;
    case 4:
        insertionSort(arr, size, direction); 
        break;
    case 5: 
        selectionSort(arr, size, direction); 
        break;
    case 6:
        quickSort(arr, 0, size - 1, direction);
        break;
    case 7:
        mergeSort(arr, 0, size - 1, direction);
        break;
    case 9:
        bogoSort(arr, size, direction);
        break;
    case 10:
        heapSort(arr, size, direction);
        break;
    default: std::cout << "Неверный выбор сортировки.\n";
        return;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Время сортировки: " << duration << " мс\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    try
    {
        const int32_t Size = 10; 
        Student students[Size];
        char direction;

        std::string choice;
        int32_t typeChoice{};
        int32_t inputChoice{};
        int32_t sortChoice{};
        
        while (true)
        {
            std::cout << "Выберите тип данных:\n1. Целые числа\n2. Вещественные числа\n3. Символы\n4. Строки\n5. Студенты\n";
            std::cin >> choice;
            if (choice.length() == 1 && isdigit(choice[0])) 
            {
                typeChoice = choice[0] - '0';
                if (typeChoice >= 1 && typeChoice <= 5)
                {
                    break;
                }
            }
            std::cout << "Неверно выбнан тип данных, введите другой(число от 1 до 5)\n";
            
        }
        while (true)
        {
            std::cout << "\nВыберите способ ввода:\n1. Ввод вручную и запись в файл\n2. Генерация случайных данных и запись в файл\n3. Чтение из файла и вывод на экран\n";
            std::cin >> choice;
            if (choice.length() == 1 && isdigit(choice[0]))
            {
                inputChoice = choice[0] - '0';
                if (inputChoice >= 1 && inputChoice <= 3)
                {
                    break;
                }
            }
            std::cout << "Неверно выбран способ ввода, введите число от 1 до 3\n";
        }
        while (true)
        {
            std::cout << "\nВыберите алгоритм сортировки:\n1. Пузырьком\n2. Шейкерная\n3. Расчёской\n4. Вставками\n5. Выбором\n6. Быстрая\n7. Слиянием\n8. Подсчётом\n9. BogoSort\n10. Пирамидальная\n";
            std::cin >> choice;
            if (choice.length() == 1 && isdigit(choice[0]))
            {
                sortChoice = choice[0] - '0';
                if ((sortChoice >= 1 && sortChoice <= 10) && !(sortChoice == 8 && (typeChoice == 4 || typeChoice == 5)))
                {
                    break;
                }
            }
            std::cout << "Неверно выбнан алгоритм сортировки, введите число от 1 до 10(для студентов и строк введите от 1 до 10, не включая 8)\n";
        }

        getDirection(direction);

        std::string infilename = "Input.txt";
        std::string outfilename = "Output.txt";
        std::string infilenames = "InStudents.txt";
        std::string outfilenames = "OutStudents.txt";

        switch (typeChoice) 
        {
        case 1: 
        { 
            int32_t size{};
            if (inputChoice == 1 || inputChoice == 2) 
            {
                inputSize(size);
                int32_t* arr = new int32_t[size];
                if (inputChoice == 1)
                {
                    inputElements(arr, size);
                }
                else
                {
                    generateRandom(arr, size);
                }
                if (sortChoice == 8) 
                {
                    performCountSort(arr, size, direction);  
                }
                else 
                {
                    performSort(arr, size, sortChoice, direction);
                }
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
                delete[] arr;
            }
            else if (inputChoice == 3) 
            {
                size = countLines(infilename);
                int32_t* arr = new int32_t[size];
                std::ifstream fin(infilename);
                CheckFile(fin);
                readFromFile(fin, arr, size);
                if (sortChoice == 8)
                {
                    performCountSort(arr, size, direction);
                }
                else
                {
                    performSort(arr, size, sortChoice, direction);
                }
                printArray(arr, size);
                delete[] arr;
            }
            break;
        }
        case 2: 
        { 
            int32_t size{};
            if (inputChoice == 1 || inputChoice == 2)
            {
                inputSize(size);
                float* arr = new float[size];
                if (inputChoice == 1)
                {
                    inputElements(arr, size);
                }
                else
                {
                    generateRandom(arr, size);
                }
                performSort(arr, size, sortChoice, direction);
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
                delete[] arr;
            }
            else if (inputChoice == 3) 
            {
                size = countLines(infilename);
                float* arr = new float[size];
                std::ifstream fin(infilename);
                CheckFile(fin);
                readFromFile(fin, arr, size);
                performSort(arr, size, sortChoice, direction);
                printArray(arr, size);
                delete[] arr;
            }
            break;
        }
        case 3: 
        {  
            int32_t size{};
            if (inputChoice == 1 || inputChoice == 2) 
            {
                inputSize(size);
                char* arr = new char[size];
                if (inputChoice == 1)
                {
                    inputElements(arr, size);
                }
                else
                {
                    generateRandom(arr, size);
                }
                performSort(arr, size, sortChoice, direction);
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
                delete[] arr;
            }
            else if (inputChoice == 3)
            {
                size = countLines(infilename);
                char* arr = new char[size];
                std::ifstream fin(infilename);
                CheckFile(fin);
                readFromFile(fin, arr, size);
                if (sortChoice == 8) 
                {
                    std::cout << "Ошибка: Сортировка подсчётом работает только для целых чисел.\n";
                }
                else 
                {
                    performSort(arr, size, sortChoice, direction);
                }
                printArray(arr, size);
                delete[] arr;
            }
            break;
        }
        case 4:
        {  
            int32_t size{};
            if (inputChoice == 1 || inputChoice == 2) 
            {
                inputSize(size);
                std::string* arr = new std::string[size];
                if (inputChoice == 1) inputElements(arr, size);
                else generateRandom(arr, size);
                if (sortChoice == 8)
                {
                    std::cout << "Ошибка: Сортировка подсчётом работает только для целых чисел.\n";
                }
                else 
                {
                    performSort(arr, size, sortChoice, direction);
                }
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
                delete[] arr;
            }
            else if (inputChoice == 3) 
            {
                size = countLines(infilename);
                std::string* arr = new std::string[size];
                std::ifstream fin(infilename);
                CheckFile(fin);
                readFromFile(fin, arr, size);
                if (sortChoice == 8)
                {
                    std::cout << "Ошибка: Сортировка подсчётом работает только для целых чисел.\n";
                }
                else 
                {
                    performSort(arr, size, sortChoice, direction);
                }
                printArray(arr, size);
                delete[] arr;
            }
            break;
        }
        case 5: 
        { 
            int32_t size{};
            if (inputChoice == 1 || inputChoice == 2)
            {
                inputSize(size);
                Student* arr = new Student[size];
                if (inputChoice == 1)
                {
                    inputStudents(arr, size);
                }
                else
                {
                    generateRandomStudents(arr, size);
                }
                if (sortChoice == 8)
                {
                    std::cout << "Ошибка: Сортировка подсчётом работает только для целых чисел.\n";
                }
                else
                {
                    performSort(arr, size, sortChoice, direction);
                }
                std::ofstream foute(outfilenames);
                CheckOutputFile(foute);
                writeStudentsToFile(foute, arr, size);
                delete[] arr;
            }
            else if (inputChoice == 3)
            {
                size = countLines(infilenames);
                Student* arr = new Student[size];
                std::ifstream fin(infilenames);
                CheckFile(fin);
                readStudents(fin, arr, size);
                if (sortChoice == 8) 
                {
                    std::cout << "Ошибка: Сортировка подсчётом работает только для целых чисел.\n";
                }
                else 
                {
                    performSort(arr, size, sortChoice, direction);
                }
                printStudentsToConsole(arr, size);
                delete[] arr;
            }
            break;
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    return 0;
}
