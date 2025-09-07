#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <chrono>

struct Student {
    int32_t course{};
    int32_t group{};
    std::string name;
    int32_t grades[3]; 


    bool operator>(Student& other) 
    {
        if (course != other.course)
        {
            return course > other.course;
        }
        if (group != other.group)
        {
            return group > other.group;
        }
        return name > other.name;
    }

    bool operator<(Student& other) 
    {
        if (course != other.course)
        {
            return course < other.course;
        }
        if (group != other.group)
        {
            return group < other.group;
        }
        return name < other.name;
    }
};

bool isMore(Student&, Student&);
bool isLess(Student&, Student&);
void CheckFile(std::ifstream&);
void CheckOutputFile(std::ofstream&);
void performCountSort(int32_t*, int32_t, char);

void inputStudents(Student*, int32_t);
void writeStudentsToFile(std::ofstream&, Student*, int32_t);
void readStudents(std::ifstream&, Student*, int32_t);
void printStudentsToConsole(Student*, int32_t);

void generateRandomStudents(Student*, int32_t);
void getDirection(char&);
void inputSize(int32_t&);
int32_t countLines(std::string&);

template<typename T>
void readFromFile(std::ifstream& file, T* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if constexpr (std::is_same_v<T, std::string>)
        {
            std::getline(file, arr[i]);
        }
        else if constexpr (std::is_same_v<T, char>)
        {
            file >> arr[i];
            file.ignore(); 
        }
        else 
        {
            file >> arr[i];
        }
    }
    file.close();
}

template<typename T>
void writeToFile(std::ofstream& file, T* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    { 
        file << arr[i] << '\t'; 
    }
    file.close();
}

template<typename T>
void printArray(T* arr, size_t size)
{
    std::cout << "Результат:\n";
    for (size_t i = 0; i < size; ++i)
    {
        if constexpr (std::is_same_v<T, std::string>)
        {
            std::cout << arr[i] << '\n'; 
        }
        else if constexpr (std::is_same_v<T, char>)
        {
            std::cout << arr[i] << '\n'; 
        }
        else
        {
            std::cout << arr[i] << " "; 
        }
    }
}

template<typename T>
void inputElements(T* arr, size_t size)
{
    std::cout << "Введите " << size << " элемента или строк, в зависимости, что требуется" << '\n';
    for (size_t i = 0; i < size; ++i)
        if constexpr (std::is_same_v<T, char>)
        {
            std::cin >> arr[i];
            std::cin.ignore(); 
        }
        else if constexpr (std::is_same_v<T, std::string>)
        {
            if (i == 0)
            {
                std::cin.ignore();
            }
            std::getline(std::cin, arr[i]);
        }
        else
        {
            std::cin >> arr[i];
        }
}

template<typename T>
void generateRandom(T* arr, size_t size)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    if constexpr (std::is_same_v<T, int32_t>)
    {
        int32_t min{};
        int32_t max{};
        std::cout << "Введите диапазон: ";
        std::cin >> min >> max;

        for (size_t i = 0; i < size; ++i)
        {
            arr[i] = min + std::rand() % (max - min + 1);
            std::cout << arr[i] << "\n";
        }
    }
    else if constexpr (std::is_same_v<T, float>)
    {
        double min{};
        double max{};
        std::cout << "Введите диапазон: ";
        std::cin >> min >> max;

        for (size_t i = 0; i < size; ++i)
        {
            double range = max - min;
            arr[i] = min + (std::rand() / (RAND_MAX + 1.0)) * range;
            std::cout << arr[i] << "\n";
        }
    }
    else if constexpr (std::is_same_v<T, char>)
    {
        char min;
        char max;
        std::cout << "Введите диапазон символов: ";
        std::cin >> min >> max;

        for (size_t i = 0; i < size; ++i)
        {
            arr[i] = static_cast<char>(min + std::rand() % (max - min + 1));
            std::cout << arr[i] << "\n";
        }
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        int32_t lenMin{};
        int32_t lenMax{};
        std::cout << "Введите диапазон длины строки: ";
        std::cin >> lenMin >> lenMax;

        for (size_t i = 0; i < size; ++i)
        {
            int32_t len = lenMin + std::rand() % (lenMax - lenMin + 1);
            std::string s;
            for (int32_t j = 0; j < len; ++j)
            {
                s += static_cast<char>('a' + std::rand() % 26);
            }
            arr[i] = s;
            std::cout << arr[i] << "\n";
        }
    }
}

#endif
