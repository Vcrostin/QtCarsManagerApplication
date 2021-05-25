#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <utility>
#include "complexdll.h"
#include "car.h"
#include "abstractreader.h"

class DataReader: public AbstractReader
{
public:
    // имя файла(вместе с разрешением)
    DataReader(const std::string& file_name);

    ~DataReader() override;

    template <typename T>
    std::istream& operator>>(T& data){
        try{
            stream_input >> data;
        }
        catch (std::exception e){
            throw std::invalid_argument(std::string(e.what()) + " " + std::to_string(number_str));
        }
    return stream_input;
    }

    std::vector<Car> read() override;

    inline std::istream& GetInput(){
        return stream_input;
    }

    AbstractReader& operator>>(Car& c) override;

    bool is_open() override;

    operator bool() override;


private:
    std::ifstream stream_input;
    int number_str = 0;
};

template <class T>
std::vector<T> ReadArray(DataReader& datareader){
    std::vector<T> Array_Of_Things;
    std::string read_string;
    int number_str = 0;
    getline(datareader.GetInput(), read_string);
        while (read_string.size()>0 && datareader) {
              Car car;
              number_str ++;
              std::stringstream sstream(read_string);
              try{
                  sstream >> car;
                }catch (std::invalid_argument e){
                    throw std::invalid_argument(std::string(e.what()) + " " + std::to_string(number_str));
                }
                catch (std::out_of_range e){
                    throw std::invalid_argument(std::string(e.what()) + " " + std::to_string(number_str));
                }
              Array_Of_Things.push_back(std::move(car));
//            auto struct_base = split(read_string, splitter);
//            if (struct_base.size() == splitter_count) {
//                Array_Of_Things.push_back(make_car(struct_base[0], struct_base[1], struct_base[2], struct_base[3]));
//            }
            getline(datareader.GetInput(), read_string);
        }
    return  std::move(Array_Of_Things);
}


