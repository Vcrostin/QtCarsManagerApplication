#include "pass_car.h"
#include <algorithm>
#include <chrono>
#include <random>

Pass_Car::Pass_Car(const std::string &number, const std::string &model,
           const std::string &color, const std::string &year)
    :Car(number,model,color,year)
{
    category = "Pass_Car";
    nums_sits = Generate(10);
}

std::string Pass_Car::repr() const
{
    return Car::repr() + " " + std::to_string(nums_sits);
}

//Pass_Car::Pass_Car(Car &&c):Car(std::move(c))
//{
//    category = "Pass_Car";
//    nums_sits = Generate(10);
//}



