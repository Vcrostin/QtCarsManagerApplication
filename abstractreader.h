#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H
#include <iostream>
#include <vector>
#include "car.h"
class AbstractReader
{
public:
    AbstractReader();

    virtual ~AbstractReader();

    virtual std::vector<Car> read() = 0;

    virtual bool is_open() = 0;

    virtual AbstractReader& operator>>(Car& c) = 0;

    virtual operator bool() = 0;
};


#endif // ABSTRACTREADER_H
