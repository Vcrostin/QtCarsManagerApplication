#ifndef ERRORTAKER_H
#define ERRORTAKER_H
#include <stdexcept>
#include <exception>
#include <string>
#include <QString>
#include "errbrowser.h"
#include <functional>

class ErrorTaker
{
public:
    ErrorTaker();

    void Error_Check(std::function<void()> func, ErrBrowser*& eb){
        try {
            func();
        } catch (std::invalid_argument e) {
            eb->WriteError(e.what());
        }
        catch (std::out_of_range e){
            eb->WriteError(e.what());
        }
    }
};

#endif // ERRORTAKER_H
