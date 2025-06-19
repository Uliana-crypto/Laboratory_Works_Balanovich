#include "Header.h"

void CheckInputFile(std::ifstream& fin)
{
    if (!fin.good())
    {
        throw "File does not exist\n";
    }
    if (!fin) 
    {
        throw "Input file error\n";
    }
    if (fin.peek() == EOF)
    {
        throw "File is empty\n";
    }
}

void CheckOutputFile(std::ofstream& fout)
{
    if (!fout.good()) 
    {
        throw "File does not exist\n";
    }
    if (!fout) 
    {
        throw "Output file error\n";
    }
}

int32_t FindCounter(std::ifstream& fin)
{
    int32_t counter{};
    int32_t numb{};
    while (fin >> numb) 
    {
        ++counter;
    }
    return counter;
}

double* readFromFile(const std::string& filename, int32_t& size)
{
    std::ifstream fin(filename);
    try 
    {
        CheckInputFile(fin);
        size = FindCounter(fin);
        fin.clear();  
        fin.seekg(0);
        double* arr = new double[size];
        for (int32_t i = 0; i < size; ++i) 
        {
            fin >> arr[i];
        }
        fin.close();
        return arr;
    }
    catch (const char* e) 
    {
        std::cout << e;
        return nullptr;
    }
}

void writeToFile(const std::string& filename, double* arr, int32_t size)
{
    std::ofstream fout(filename, std::ios::app);
    try
    {
        CheckOutputFile(fout);
        for (int32_t i = 0; i < size; i++)
        {
            fout << arr[i] << '\n';
        }
        fout.close();
    }
    catch (const char* e)
    {
        std::cout << e;
    }
}

double* readFromConsole(int32_t& size)
{
    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    double* arr = new double[size];
    for (int32_t i = 0; i < size; ++i)
    {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i];
    }
    return arr;
}

void OutputArray(std::ostream& fout, double* arr, int32_t size)
{
    for (int32_t i = 0; i < size; ++i)
    {
        fout << arr[i] << ' ';
    }
    fout << '\n';
}

void quickSort(double* arr, int32_t left, int32_t right, bool ascending) 
{
    if (left < right) 
    {
        int32_t pivot = arr[right];
        int32_t i = left - 1;

        for (int32_t j = left; j < right; ++j) 
        {
            if ((ascending && arr[j] < pivot) || (!ascending && arr[j] > pivot)) 
            {
                std::swap(arr[++i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[right]);
        int32_t partitionIndex = i + 1;

        quickSort(arr, left, partitionIndex - 1, ascending);
        quickSort(arr, partitionIndex + 1, right, ascending);
    }
}

void insertionSort(double* arr, int32_t size, bool ascending)
{
    for (int32_t i = 1; i < size; ++i) 
    {
        double key = arr[i];
        int32_t j = i - 1;
        while (j >= 0 && ((ascending && arr[j] > key) || (!ascending && arr[j] < key)))
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(double* arr, int32_t size, bool ascending) 
{
    for (int32_t i = 0; i < size - 1; ++i) 
    {
        int32_t minIndex = i;
        for (int32_t j = i + 1; j < size; ++j)
        {
            if ((ascending && arr[j] < arr[minIndex]) || (!ascending && arr[j] > arr[minIndex])) 
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
void mergeSort(double* arr, int32_t left, int32_t right, bool ascending)
{
    if (left >= right)
    {
        return;
    }

    int32_t mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, ascending);
    mergeSort(arr, mid + 1, right, ascending);

    int32_t size1 = mid - left + 1;
    int32_t size2 = right - mid;

    double* leftArr = new double[size1];
    double* rightArr = new double[size2];

    for (int32_t i = 0; i < size1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int32_t i = 0; i < size2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    int32_t i = 0, j = 0, k = left;
    while (i < size1 && j < size2)
    {
        if ((ascending && leftArr[i] <= rightArr[j]) || (!ascending && leftArr[i] >= rightArr[j]))
        {
            arr[k++] = leftArr[i++];
        }
        else 
        {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < size1)
    {
        arr[k++] = leftArr[i++];
    }
    while (j < size2)
    {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

void bubbleSortOptimized(double* arr, int32_t size, bool ascending)
{
    bool swapped{};
    for (int i = 0; i < size - 1; i++) 
    {
        swapped = false;
        for (int32_t j = 0; j < size - i - 1; j++) 
        {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1]))
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

int32_t compareDecimals(const void* a, const void* b)
{
    double num1 = *(double*)a;
    double num2 = *(double*)b;
    return (int32_t)(num2 * 1000) - (int32_t)(num1 * 1000);
}

void qsortDescending(double* arr, int32_t size)
{
    qsort(arr, size, sizeof(double), compareDecimals);
}

void InputConcreteStudent(Student& student, int32_t number)
{
    std::cout << "Input first name of the " << number << "th student: ";
    std::getline(std::cin, student.firstName);
    std::cout << "Input surname: ";
    std::getline(std::cin, student.surname);
    std::cout << "Input course number: ";
    std::cin >> student.course;
    std::cin.ignore();
    std::cout << "Input group: ";
    std::getline(std::cin, student.group);

    std::cout << "Input 5 marks:\n";
    for (int32_t i = 0; i < 5; ++i)
    {
        std::cin >> student.marks[i];
        if (student.marks[i] < 0 || student.marks[i] > 10) 
        {
            throw std::invalid_argument("Marks must be non-negative and smaller or equal to 10");
        }
    }
    std::cin.ignore();
}

void InputAllStudents(Student* students, int32_t size)
{
    for (int32_t i = 0; i < size; ++i) 
    {
        InputConcreteStudent(students[i], i + 1);
    }
}

void OutputConcreteStudent(const Student& student)
{
    std::cout << student.firstName << " " << student.surname << " Course: " << student.course << " Group: " << student.group << " Average Grade: " << student.getAverageGrade() << "\n";
}

void OutputAllStudents(const Student* students, int32_t size)
{
    for (int32_t i = 0; i < size; ++i)
    {
        OutputConcreteStudent(students[i]);
    }
}

int32_t CompareByAverageGrade(const void* stud1, const void* stud2)
{
    const Student* s1 = (const Student*)stud1;
    const Student* s2 = (const Student*)stud2;

    double avg1 = s1->getAverageGrade();
    double avg2 = s2->getAverageGrade();

    return (avg1 - avg2 > 0) - (avg1 - avg2 < 0);
}

void SortByAverageGrade(Student* students, int32_t size)
{
    qsort(students, size, sizeof(Student), CompareByAverageGrade);
}