#include "jsonreader.h"

jsonReader::~jsonReader()
{
    stream.close();
}

jsonReader::jsonReader(std::string file_name):stream(file_name)
{
}

std::vector<Car> jsonReader::read()
{
    std::vector<Car> cars;
    json j;
    stream >> j;
    for(auto& e:j){
        auto c = e.get<Car>();
        cars.push_back(std::move(c));
    }

//    for(const auto& c:cars){
//        std::cout<<c.GetNumber()<<": "<<c.GetModel()<<" "<<static_cast<int>(c.GetColor())<<" (" << c.GetYear()<<") "<<std::endl;
//    }
    return cars;
}

bool jsonReader::is_open()
{
    return stream.is_open();
}

AbstractReader &jsonReader::operator>>(Car &c)
{
    stream>>c;
    return dynamic_cast<AbstractReader&>(*this);
}

jsonReader::operator bool()
{
    return !stream.eof();
}
