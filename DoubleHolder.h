//
// Created by Илья Коломин on 10.09.2021.
//
#include "BaseHolder.h"

#ifndef IUTESTTASK_DOUBLEHOLDER_H
#define IUTESTTASK_DOUBLEHOLDER_H


class DoubleHolder : public BaseHolder {
private:
    double value;
public:
    explicit DoubleHolder(double);
    std::string toString() override;
    size_t size() override;
};


#endif //IUTESTTASK_DOUBLEHOLDER_H
