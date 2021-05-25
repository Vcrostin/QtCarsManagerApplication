#pragma once
#include "abstractreader.h"
#include "car.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

using json = nlohmann::json;
class jsonReader : public AbstractReader
{
public:
    ~jsonReader() override;
    jsonReader(std::string file_name);
    std::vector<Car> read() override;
    bool is_open() override;
    AbstractReader& operator>>(Car& c) override;
    operator bool() override;
private:
    std::fstream stream;
};


