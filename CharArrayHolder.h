//
// Created by Илья Коломин on 10.09.2021.
//
#include "BaseHolder.h"

#ifndef IUTESTTASK_CHARARRAYHOLDER_H
#define IUTESTTASK_CHARARRAYHOLDER_H


class CharArrayHolder : public BaseHolder {
private:
    char value[10];
public:
    explicit CharArrayHolder(const char[10]);
    std::string toString() override;
    size_t size() override;
};


#endif //IUTESTTASK_CHARARRAYHOLDER_H
