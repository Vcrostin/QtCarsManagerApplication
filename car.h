#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
#define GET_VARI_NAME(a) #a

class Car {
public:
    //Car(const Car& car);
    Car();
    Car(const std::string& number, const std::string& model,
        const std::string& color, const std::string& year);
    Car(const Car& c) = delete;
    Car(Car&& c);
    Car& operator=(const Car& c) = delete;
    Car &operator=(Car&& c){
        if(this != &c){
            this->category = std::move(c.category);
            this->splitter = std::move(c.splitter);
            this->Car_Number = std::move(c.Car_Number);
            this->Car_Color = std::move(c.Car_Color);
            this->Car_Model = std::move(c.Car_Model);
        }
        return *this;
    }
    ~Car();

    virtual std::string repr() const;

    enum class Color {
        RED,
        GREEN,
        BLACK,
        BLUE,
        PURPLE,
        WHITE
    };

    friend std::ostream& operator << (std::ostream& stream, const Car& car);

    friend std::istream& operator >> (std::istream& stream, Car& car);

    bool operator <(Car& car);

    void from_json(const json& j);

    std::string GetModel() const;

    int GetNumber() const;

    Car::Color GetColor() const;

    int GetYear() const;

    std::string Print() const;

    char GetSplitter() const;


private:

    int Car_Number = -1;
    std::string Car_Model;
    Color Car_Color;
    int Year_Of_Create;
    char splitter = ';';
    int Gen_Id(int a = -1);
protected:
    std::string category = "";
    int Generate(int a);
};

void from_json(const json& j,Car& c);

//std::ostream& operator << (std::ostream& stream, const Car& car);

//std::istream& operator >> (std::istream& stream, Car& car);

inline Car make_car(const std::string& number, const std::string& model,
                    const std::string& color, const std::string& year) {
    return Car{number,model,color,year};
}

std::vector<std::string> Make_enum_To_String();

void sort_car(std::vector<Car>& cars);

void swap(Car& c1,Car& c2);
