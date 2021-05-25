#include "datareader.h"
#include <string>
#include <fstream>

DataReader::DataReader(const std::string &file_name):AbstractReader(),stream_input(file_name){

}

DataReader::~DataReader(){
    stream_input.close();
}

std::vector<Car> DataReader::read()
{
    number_str = 0;
    std::vector<Car> Array_Of_Things;
    std::string read_string;
    getline(stream_input, read_string);
        while (read_string.size()>0) {
              number_str++;
              Car car;
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
            getline(stream_input, read_string);
        }
        return  (Array_Of_Things);
}

AbstractReader &DataReader::operator>>(Car &c)
{
    stream_input>>c;
    return dynamic_cast<AbstractReader&>(*this);
}

bool DataReader::is_open()
{
    return stream_input.is_open();
}

DataReader::operator bool()
{
    return !stream_input.eof();
}

