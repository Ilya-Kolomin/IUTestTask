//
// Created by Илья Коломин on 10.09.2021.
//

#include "IntHolder.h"

IntHolder::IntHolder(int value_) : value(value_) { }

std::string IntHolder::toString() {
    return std::to_string(value);
}

size_t IntHolder::size() {
    return sizeof(IntHolder);
}
