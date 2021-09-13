//
// Created by Илья Коломин on 10.09.2021.
//

#include "DoubleHolder.h"

DoubleHolder::DoubleHolder(double value_) : value(value_) { }

std::string DoubleHolder::toString() {
    return std::to_string(value);
}

size_t DoubleHolder::size() {
    return sizeof(DoubleHolder);
}
