//
// Created by Илья Коломин on 10.09.2021.
//
#include <string>

#ifndef IUTESTTASK_BASEHOLDER_H
#define IUTESTTASK_BASEHOLDER_H


class BaseHolder {
public:
    // virtual function to print value
    virtual std::string toString() = 0;
    virtual size_t size() = 0;
};



#endif //IUTESTTASK_BASEHOLDER_H
