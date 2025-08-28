#include "operations.h"
#include "sort.h"

int main() 
{
    SetConsoleCP('1251');
    SetConsoleOutputCP('1251');
    setlocale(LC_ALL, "Russian");
   try
   {
        const int32_t Size = 10;
        Student students[Size];
        char direction;

        int32_t typeChoice{};
        int32_t inputChoice{};
        int32_t sortChoice{};

        std::cout << "Выберите тип данных : \n";
        std::cout << "1. Целые числа\n2. Вещественные числа\n3. Символы\n4. Строки\n5. Студенты\n";
        std::cin >> typeChoice;

        std::cout << "\nВыберите способ ввода:\n";
        std::cout << "1. Ввод вручную и запись в файл\n";
        std::cout << "2. Генерация случайных данных и запись в файл\n";
        std::cout << "3. Чтение из файла и вывод на экран\n";
        std::cin >> inputChoice;

        std::cout << "\nВыберите алгоритм сортировки:\n";
        std::cout << "1. Пузырьком\n2. Шейкерная\n3. Расчёской\n4. Вставками\n5. Выбором\n";
        std::cout << "6. Быстрая\n7. Слиянием\n8. Подсчётом\n9. BogoSort\n10. Пирамидальная\n";
        std::cin >> sortChoice;

        getDirection(direction);

        std::string infilename = "Input.txt";
        std::string outfilename = "Output.txt";
        std::string infilenames = "InStudents.txt";
        std::string outfilenames = "OutStudents.txt";

        switch (typeChoice)
        {
        case 1: { 
            
            if (inputChoice == 1) {
                int32_t size{};
                inputSize(size);
                int32_t* arr = new int32_t[size];
                inputElements(arr, size);
                switch (sortChoice) {
                case 1: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    bubbleSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки пузырьком: " << duration << " мс\n";
                    break;
                }
                case 2: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    shakerSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время шейкерной сортировки: " << duration << " мс\n";
                    break;
                }
                case 3: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    combSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время расчёсной сортировки: " << duration << " мс\n";
                    break;
                }
                case 4: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    insertionSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки вставками: " << duration << " мс\n";
                    break;
                }
                case 5: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    selectionSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки выбором: " << duration << " мс\n";
                    break;
                }
                case 6: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    quickSort(arr, 0, size - 1, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время быстрой сортировки: " << duration << " мс\n";
                    break;
                }
                case 7: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    mergeSort(arr, 0, size - 1, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки слиянием: " << duration << " мс\n";
                    break;
                }
                case 8: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    countSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки подсчётом: " << duration << " мс\n";
                    break;
                }
                case 9: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    bogoSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время BogoSort: " << duration << " мс\n";
                    break;
                }
                case 10: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    heapSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время пирамидальной сортировки: " << duration << " мс\n";
                    break;

                }
                       std::ofstream fout(outfilename);
                       CheckOutputFile(fout);
                       writeToFile(fout, arr, size);
                }
            }
            else if (inputChoice == 2) {
                int32_t size{};
                inputSize(size);
                int32_t* arr = new int32_t[size];
                generateRandom(arr, size);
                switch (sortChoice) {
                case 1: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    bubbleSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки пузырьком: " << duration << " мс\n";
                    break;
                }
                case 2: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    shakerSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время шейкерной сортировки: " << duration << " мс\n";
                    break;
                }
                case 3: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    combSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время расчёсной сортировки: " << duration << " мс\n";
                    break;
                }
                case 4: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    insertionSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки вставками: " << duration << " мс\n";
                    break;
                }
                case 5: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    selectionSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки выбором: " << duration << " мс\n";
                    break;
                }
                case 6: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    quickSort(arr, 0, size - 1, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время быстрой сортировки: " << duration << " мс\n";
                    break;
                }
                case 7: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    mergeSort(arr, 0, size - 1, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки слиянием: " << duration << " мс\n";
                    break;
                }
                case 8: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    countSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки подсчётом: " << duration << " мс\n";
                    break;
                }
                case 9: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    bogoSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время BogoSort: " << duration << " мс\n";
                    break;
                }
                case 10: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    heapSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время пирамидальной сортировки: " << duration << " мс\n";
                    break;

                }
                }
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
            }
            else if (inputChoice == 3) {
                int32_t size = countLines(infilename); 
                int32_t* arr = new int32_t[size];
                std::ifstream fin(infilename);
                checkFile(fin);
                readFromFile(fin, arr, size);
                switch (sortChoice) {
                case 1: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    bubbleSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки пузырьком: " << duration << " мс\n";
                    break;
                }
                case 2: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    shakerSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время шейкерной сортировки: " << duration << " мс\n";
                    break;
                }
                case 3: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    combSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время расчёсной сортировки: " << duration << " мс\n";
                    break;
                }
                case 4: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    insertionSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки вставками: " << duration << " мс\n";
                    break;
                }
                case 5: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    selectionSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки выбором: " << duration << " мс\n";
                    break;
                }
                case 6: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    quickSort(arr, 0, size - 1, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время быстрой сортировки: " << duration << " мс\n";
                    break;
                }
                case 7: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    mergeSort(arr, 0, size - 1, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки слиянием: " << duration << " мс\n";
                    break;
                }
                case 8: {  
                    auto start = std::chrono::high_resolution_clock::now();
                    countSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время сортировки подсчётом: " << duration << " мс\n";
                    break;
                }
                case 9: { 
                    auto start = std::chrono::high_resolution_clock::now();
                    bogoSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время BogoSort: " << duration << " мс\n";
                    break;
                }
                case 10: { 
                    auto start = std::chrono::high_resolution_clock::now();
                    heapSort(arr, size, direction);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    std::cout << "Время пирамидальной сортировки: " << duration << " мс\n";
                    break;

                }
                }
                printArray(arr, size);
            }
            break;
        }

        case 2: { 
            
            if (inputChoice == 1) {
                int32_t size{};
                inputSize(size);
                float* arr = new float[size];
                inputElements(arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 8: countSort(arr, size, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
            }
            else if (inputChoice == 2) {
                int32_t size{};
                inputSize(size);
                float* arr = new float[size];
                generateRandom(arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 8: countSort(arr, size, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
            }
            else if (inputChoice == 3) {
                int32_t size = countLines(infilename);
                float* arr = new float[size];
                std::ifstream fin(infilename);
                checkFile(fin);
                readFromFile(fin, arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 8: countSort(arr, size, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                printArray(arr, size);
            }
            break;
        }

        case 3: { 
            if (inputChoice == 1) {
                int32_t size{};
                inputSize(size);
                char* arr = new char[size];
                inputElements(arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 8: countSort(arr, size, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
            }
            else if (inputChoice == 2) {
                int32_t size{};
                inputSize(size);
                char* arr = new char[size];
                generateRandom(arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 8: countSort(arr, size, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
            }
            else if (inputChoice == 3) {
                int32_t size = countLines(infilename);
                char* arr = new char[size];
                std::ifstream fin(infilename);
                checkFile(fin);
                readFromFile(fin, arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 8: countSort(arr, size, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                printArray(arr, size);
            }
            break;
        }

        case 4: { 
           
            if (inputChoice == 1) {
                int32_t size{};
                inputSize(size);
                std::string* arr = new std::string[size];
                inputElements(arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
            }
            else if (inputChoice == 2) {
                int32_t size{};
                inputSize(size);
                std::string* arr = new std::string[size];
                generateRandom(arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                std::ofstream fout(outfilename);
                CheckOutputFile(fout);
                writeToFile(fout, arr, size);
            }
            else if (inputChoice == 3) {
                int32_t size = countLines(infilename);
                std::string* arr = new std::string[size];
                std::ifstream fin(infilename);
                checkFile(fin);
                readFromFile(fin, arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                    case 2: shakerSort(arr, size, direction); break;
                    case 3: combSort(arr, size, direction); break;
                    case 4: insertionSort(arr, size, direction); break;
                    case 5: selectionSort(arr, size, direction); break;
                    case 6: quickSort(arr, 0, size - 1, direction); break;
                    case 7: mergeSort(arr, 0, size - 1, direction); break;
                    case 9: bogoSort(arr, size, direction); break;
                    case 10: heapSort(arr, size, direction); break;
                }
                printArray(arr, size);
            }
            break;
        }
        case 5: { 
            if (inputChoice == 1) {
                int32_t size{};
                inputSize(size);
                Student* arr = new Student[size];
                inputStudents(arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                std::ofstream foute(outfilenames);
                CheckOutputFile(foute);
                writeStudentsToFile(foute, arr, size);
            }
            else if (inputChoice == 2) {
                int32_t size{};
                inputSize(size);
                Student* arr = new Student[size];
                generateRandomStudents(arr, size); 
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                std::ofstream foute(outfilenames);
                CheckOutputFile(foute);
                writeStudentsToFile(foute, arr, size);
            }
            else if (inputChoice == 3) {
                int32_t size = countLines(infilenames);
                Student* arr = new Student[size];
                std::ifstream fin(infilenames);
                checkFile(fin);
                readStudents(fin, arr, size);
                switch (sortChoice) {
                case 1: bubbleSort(arr, size, direction); break;
                case 2: shakerSort(arr, size, direction); break;
                case 3: combSort(arr, size, direction); break;
                case 4: insertionSort(arr, size, direction); break;
                case 5: selectionSort(arr, size, direction); break;
                case 6: quickSort(arr, 0, size - 1, direction); break;
                case 7: mergeSort(arr, 0, size - 1, direction); break;
                case 9: bogoSort(arr, size, direction); break;
                case 10: heapSort(arr, size, direction); break;
                }
                printStudentsToConsole(arr, size);
            }
            break;
        }
        default:
            std::cout << "Неверный выбор типа данных.\n";
            return 1;
        }
   }
   catch (const std::exception& ex)
   {
        std::cout << ex.what() << "\n";
   }
   return 0;
}

