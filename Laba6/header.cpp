#include "header.h"

int32_t countWords(char* str, const char* delimiters)
{
    char* copy = new char[strlen(str) + 1];
    strcpy(copy, str);

    int32_t counter = 0;
    char* temp = strtok(copy, delimiters);

    while (temp != nullptr) 
    {
        ++counter;
        temp = strtok(nullptr, delimiters);
    }
    return counter;
}

void checkwords(char* str, const char* delimiters) 
{
    int32_t counter = countWords(str, delimiters);
    if (counter < 2) 
    {
        throw std::logic_error("The line must contain at least two words");
    }
}

char* findmaxword(char* str, const char* delimiters) 
{
    char* copy = new char[strlen(str) + 1];
    strcpy(copy, str);

    char* temp = strtok(copy, delimiters);
    char* maxWord = temp;
    int32_t maxLength = strlen(temp);

    while (temp != nullptr)
    {
        if (strlen(temp) > maxLength)
        {
            maxLength = strlen(temp);
            maxWord = temp;
        }
        temp = strtok(nullptr, delimiters);
    }
    return maxWord;
}

char* findminword(char* str, const char* delimiters)
{
    char* copy = new char[strlen(str) + 1];
    strcpy(copy, str);

    char* temp = strtok(copy, delimiters);
    char* minWord{NULL };
    int32_t minLength = 1000;

    while (temp != nullptr) 
    {
        if (strlen(temp) < minLength)
        {
            minLength = strlen(temp);
            minWord = temp;
        }
        temp = strtok(nullptr, delimiters);
    }

    return minWord;
}

char* createNewStringWithSwapMaxMin(char* str, const char* delimiters)
{
    size_t n{ strlen(str) };
    char* max_word = new char[strlen(str) + 1];
    strcpy(max_word, "");
    int32_t index_max{ FindMaxIndex(str, delimiters) };
    strcpy(max_word, findmaxword(str, delimiters));
    char* min_word = new char[strlen(str) + 1];
    strcpy(min_word, "");
    int32_t index_min{ FindMinIndex(str, delimiters) };
    strcpy(min_word, findminword(str, delimiters));
    char* result = new char[strlen(str) + 1];
    strcpy(result, "");
  
    if (index_max < index_min) {
        char* temp1 = new char[strlen(str) - index_min];
        strcpy(temp1, "");
        strncpy(temp1, str, index_max);
        strcat(result, temp1);
        strcat(result, min_word);
        strcpy(temp1, "");
        strncpy(temp1, str, index_min );
        strcat(temp1, "\0");
        strcat(result, temp1 + index_max + strlen(max_word));
        strcat(result, max_word);
        strcat(result, str + index_min + strlen(min_word));
    }
    else if (index_max > index_min)
    {
        char* temp2 = new char[strlen(str) - index_max - 3];
        strcpy(temp2, "");
        strncpy(temp2, str, index_min);
        strcat(result, temp2);
        strcat(result, max_word);
        strcpy(temp2, "");
        strncpy(temp2, str, index_max);
        strcat(temp2, "\0");
        strcat(result, temp2 + index_min + strlen(min_word));
        strcat(result, min_word);
        strcat(result, str + index_max + strlen(max_word));

    }
    delete[]max_word;
    delete[]min_word;
    return result;
}

int32_t FindMaxIndex(char* str, const char* delimiters)
{
    return strstr(str, findmaxword(str, delimiters)) - str;
}
int32_t FindMinIndex(char* str, const char* delimiters)
{
    return strstr(str, findminword(str, delimiters)) - str;
}