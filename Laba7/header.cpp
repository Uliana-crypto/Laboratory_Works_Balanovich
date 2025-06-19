#include "header.h"

//9. Строка состоит из слов, разделенных пробелами.
//Поместить в начало строки слова, содержащие только цифры, а затем – все остальные слова.
//Порядок слов внутри заданных групп не должен изменяться.

bool isNumeric(const std::string& word) 
{
    for (char ch : word)
    {
        if (std::isdigit(ch))
        {
            return true;
        }
    }
    return false;
}
void rearrangeWords(std::string& str)
{
    if (str.empty())
    {
        throw std::invalid_argument("Empty string passed");
    }

    std::string numericWords;
    std::string otherWords;
    std::string word;

    for (size_t i = 0; i <= str.length(); ++i) 
    {
        if (i == str.length() || str[i] == ' ')
        {
            if (!word.empty())
            {
                if (isNumeric(word)) 
                {  
                    numericWords += word + " ";
                }
                else 
                {
                    otherWords += word + " ";
                }
            }
            word = "";
        }
        else
        {
            word += str[i];
        }
    }

    if (numericWords.empty() && otherWords.empty())
    {
        throw std::runtime_error("The string is empty or contains only spaces");
    }

    str = numericWords + otherWords;
}