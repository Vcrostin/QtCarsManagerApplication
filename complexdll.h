#pragma once
#include <vector>
#include <algorithm>
#include <string>

#define SPLITTER ';'
class ComplexDll
{
public:
    ComplexDll();
};


std::vector<std::string> split(const std::string& str, char delim);

template<class T>
std::ostream& operator << (std::ostream& stream, const std::vector<T> vct){
    for(const auto& v:vct){
        stream << v << "\n";
    }
    return stream;
}
