#pragma once
#include <string>
#include "car.h"
class Freight_Car : public Car
{
public:
    Freight_Car(const std::string& number, const std::string& model,
                const std::string& color, const std::string& year);
//    Freight_Car(Car&& c);

    std::string repr() const;
protected:
    int weight;
};

