#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <stdexcept>
#include <fstream>

#include <string>
#include <cstdlib>
void CheckInputFile(std::ifstream&);

void CheckOutputFile(std::ofstream&);

double* readFromFile(const std::string&, int32_t&);

void writeToFile(const std::string&, double*, int32_t);

double* readFromConsole(int32_t&);
int32_t FindCounter(std::ifstream&);
int32_t compareDecimals(const void*, const void*);

void OutputArray(std::ostream&, double*, int32_t);
void quickSort(double*, int32_t, int32_t, bool);
void insertionSort(double*, int32_t, bool);
void selectionSort(double*, int32_t, bool);
void mergeSort(double*, int32_t, int32_t, bool);
void bubbleSortOptimized(double*, int32_t, bool);
void qsortDescending(double*, int32_t);
struct Student {
    std::string firstName;
    std::string surname;
    int32_t course{};
    std::string group;
    int32_t marks[5];
    double getAverageGrade() const
    {
        double sum = 0;
        for (int32_t i = 0; i < 5; ++i)
        {
            sum += marks[i];
        }
        return sum / 5.0;
    }
};

int32_t CompareByAverageGrade(const void*, const void*);
void SortByAverageGrade(Student*, int32_t);
void InputConcreteStudent(Student&, int32_t);
void InputAllStudents(Student*, int32_t);
void OutputConcreteStudent(const Student&);
void OutputAllStudents(const Student*, int32_t);

#endif