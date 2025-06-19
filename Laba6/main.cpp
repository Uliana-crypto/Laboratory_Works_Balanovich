#include "header.h"


//1. Строка состоит не менее чем из двух слов.Преобразовать её по следующему правилу :
//найти первое из самых длинных и последнее из самых коротких слов и поменять их местами.
//Количество пробелов между словами должно сохраниться.



int main()
{
    try 
    {
        const int32_t MAX_LENGTH = 300;
        char str[MAX_LENGTH];
        char delimiters[20];

        std::cout << "Enter a string: ";
        std::cin.getline(str, MAX_LENGTH);
        std::cout << "Enter delimiters: ";
        std::cin.getline(delimiters, 20);
        checkwords(str, delimiters);
        std::cout << createNewStringWithSwapMaxMin(str, delimiters);

    }
    catch (std::logic_error& e) 
    {
        std::cout << e.what();
    } 
    catch (...) 
    {
        std::cerr << "An unexpected exception occurred./n";
    }

    return 0;
}