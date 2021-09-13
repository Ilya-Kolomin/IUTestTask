//
// Created by Илья Коломин on 10.09.2021.
//

#include "CharArrayHolder.h"
#include <cstring>

CharArrayHolder::CharArrayHolder(const char * value_) {
    strcpy(value, value_);
}

std::string CharArrayHolder::toString() {
    return std::string(value);
}

size_t CharArrayHolder::size() {
    return sizeof(CharArrayHolder);
}
