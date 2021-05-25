#pragma once
#include "car.h"
class Pass_Car:public Car
{
public:
    Pass_Car(const std::string& number, const std::string& model,
         const std::string& color, const std::string& year);
//    Pass_Car(Car&& c);

    std::string repr() const;
protected:
    int nums_sits;
};

