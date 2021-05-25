#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <fstream>
#include <car.h>
#include <iomanip>
#include <random>
#include "complexdll.h"
#include <exception>
#include <stdexcept>
#include <utility>
#include <chrono>


Car::Car(){
    Car_Number = Gen_Id();
}

Car::Car(const std::string& number, const std::string& model,
         const std::string& color, const std::string& year) {
    {
        std::stringstream stream(number);
        stream >> Car_Number;
    }
    {
        std::stringstream stream(color);
        int clr;
        stream >> clr;
        Car_Color = (Color)clr;
    }
    Car_Model = model;
    {
        std::stringstream stream(year);
        stream >> Year_Of_Create;
    }
    Gen_Id(atoi(number.c_str()));
}

Car::Car(Car &&c)
{
    Car_Number = c.Car_Number;
    Car_Color = c.Car_Color;
    Car_Model = c.Car_Model;
    Year_Of_Create = c.Year_Of_Create;
}




std::string Car::GetModel() const{
    return Car_Model;
}

int Car::GetNumber() const{
    return Car_Number;
}

Car::Color Car::GetColor() const{
    return Car_Color;
}

int Car::GetYear() const{
    return Year_Of_Create;
}


char Car::GetSplitter() const{
    return splitter;
}

int Car::Gen_Id(int a)
{
    static int car_counter = 0;
    if(a==-1){
        return ++car_counter;
    }
    else{
        car_counter = std::max(car_counter,a);
        return car_counter;
    }
}

int Car::Generate(int a)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    return generator()%a + 1;

}

std::ostream& operator<<(std::ostream& stream, const Car& car) {
    stream << std::to_string(car.GetNumber()) << car.GetSplitter()
           << car.GetModel() << car.GetSplitter()
           << std::to_string(static_cast<int>(car.GetColor())) << car.GetSplitter()
           << std::to_string(car.GetYear());
    return stream;
}

std::istream& operator>>(std::istream& stream, Car& car){
    if(car.GetNumber()==-1)
        return stream;
    std::string str;
    std::getline(stream,str);
    if(str.size()==0){
        car.Car_Number = -1;
        throw std::invalid_argument("empty string");
    }
    std::vector<std::string> vct_readed = split(str, SPLITTER);
    if(vct_readed.size() != 4)
        throw std::invalid_argument("non corect size of string");
    car.Car_Number = stoi(vct_readed[0]);
    car.Car_Model = vct_readed[1];
    car.Car_Color = static_cast<Car::Color>(stoi(vct_readed[2]));
    car.Year_Of_Create = stoi(vct_readed[3]);
    return stream;
}

std::string Car::Print() const{
    std::string output_data;
    output_data = std::to_string(Car_Number) + " " +
            Car_Model + " " + std::to_string(static_cast<int>(Car_Color)) +
            " " + std::to_string(Year_Of_Create);
    return output_data;
}

void from_json(const json& j,Car& c){
    c.from_json(j);
}

Car::~Car(){

}

std::string Car::repr() const
{
    return Print() + " " + category;
}

bool Car::operator <(Car &car)
{
    return this->GetModel()<car.GetModel();
}

void Car::from_json(const json &j)
{
    j.at("id").get_to(Car_Number);
    j.at("model").get_to(Car_Model);
    j.at("color").get_to(Car_Color);
    j.at("year").get_to(Year_Of_Create);

}


std::vector<std::string> Make_enum_To_String(){
    std::vector<std::string> vct_return({{"RED"},
                          {"GREEN"},
                          {"BLACK"},
                          {"BLUE"},
                          {"PURPLE"},
                          {"WHITE"}});
    return vct_return;
}

void sort_car(std::vector<Car> &cars)
{
    std::sort(cars.begin(),cars.end());
}

void swap(Car &c1, Car &c2)
{
    Car c3 = std::move(c1);
    c1 = std::move(c2);
    c2 = std::move(c3);
}

