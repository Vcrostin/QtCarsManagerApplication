#pragma once
#include "car.h"
#include <string>
class Bus:public Car
{
public:
    Bus(const std::string& number, const std::string& model,
         const std::string& color, const std::string& year);
//    Bus(Car&& c);

    std::string repr() const;
protected:
    int number_of_different_drivers;
};

