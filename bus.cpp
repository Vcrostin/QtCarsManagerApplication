#include "bus.h"


Bus::Bus(const std::string &number, const std::string &model,
         const std::string &color, const std::string &year):Car(number,model,color,year)
{
    category = "Bus";
    number_of_different_drivers = Generate(15);
}

std::string Bus::repr() const
{
    return Car::repr() + " " + std::to_string(number_of_different_drivers);
}

//Bus::Bus(Car &&c)
//{
//    category = "Pass_Car";
//    nums_sits = Generate(10);
//}
