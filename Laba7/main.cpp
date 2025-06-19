#include "header.h"

int main() 
{
    try 
    {
        std::string input;
        std::cout << "Enter a string: ";
        std::getline(std::cin, input);
        rearrangeWords(input);
        std::cout << "Processed string: " << input << "\n";

    }
    catch (const std::invalid_argument& e) 
    {
        std::cout << e.what() << "\n";
    }
    catch (const std::runtime_error& e) 
    {
        std::cout << e.what() << "\n";
    }
    catch (...)
    {
        std::cout << "Unknown exception" << "\n";
    }

    return 0;
}