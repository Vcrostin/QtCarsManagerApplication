#include "complexdll.h"

ComplexDll::ComplexDll()
{
}

std::vector<std::string> split(const std::string& str, char delim)
{
    std::vector<std::string> tokens;

    auto start = str.begin(), end = find(start, str.end(), delim);
    while (start != str.end())
    {
        tokens.push_back(std::string(start, end));
        start = end != str.end() ? end + 1 : end;
        while (start != str.end() && *start == delim)
            start++;
        end = find(start, str.end(), delim);
    }

    return tokens;
}


