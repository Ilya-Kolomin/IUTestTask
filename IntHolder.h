//
// Created by Илья Коломин on 10.09.2021.
//
#include "BaseHolder.h"

#ifndef IUTESTTASK_INTHOLDER_H
#define IUTESTTASK_INTHOLDER_H


class IntHolder : public BaseHolder {
private:
    int value;
public:
    explicit IntHolder(int);
    std::string toString() override;
    size_t size() override;
};


#endif //IUTESTTASK_INTHOLDER_H
