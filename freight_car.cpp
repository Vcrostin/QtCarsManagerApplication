#include "freight_car.h"

Freight_Car::Freight_Car(const std::string &number, const std::string &model,
                         const std::string &color, const std::string &year)
                  :Car(number,model,color,year)
{
    category = "Freight_Car";
    weight = Generate(40);
}
std::string Freight_Car::repr() const
{
    return Car::repr() + " " + std::to_string(weight);
}

//Freight_Car::Freight_Car(Car &&c):Car(std::move(c))
//{
//    category = "Freight_Car";
//}
