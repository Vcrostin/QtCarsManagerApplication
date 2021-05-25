#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <vector>
#include "complexdll.h"

class DataWriter
{
public:
    DataWriter(const std::string& file_name);
    ~DataWriter();

    int DataSource(const std::string& file_name);
template <class T>
    void WriteFile(const T& wr){
        stream_output << wr << std::endl;
    }
template <class T>
    void WriteFile(T&& wr){
        stream_output << wr <<std::endl;
    }

    template <typename T>
    std::ostream& operator<<(const T& data){
        if(!stream_output.is_open()){
            throw std::invalid_argument("Choose file for output data first");
        }
        stream_output << data;
        return stream_output;
    }


    inline std::ostream& GetOutput(){
        return stream_output;
    }

private:
    std::ofstream stream_output;
};

//template <class T>
//std::ostream& operator<<(std::ostream& stream, const std::vector<T>& data){
//    for(const auto& d : data){
//        stream<<d<<"\n";
//    }
//    return stream;
//}
