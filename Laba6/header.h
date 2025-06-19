#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int32_t countWords(char*, const char*);
void checkwords(char*, const char*);
char* findmaxword(char*, const char*);
char* findminword(char*, const char*);
char* createNewStringWithSwapMaxMin(char*,const char*);
int32_t FindMaxIndex(char*, const char*);
int32_t FindMinIndex(char*, const char*);

#endif // HEADER_H