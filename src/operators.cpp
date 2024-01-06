//
// Created by maximilian-tuxedo on 28.12.2023.
//

#include "operators.h"
#include "types.h"

int ohpc::Adder::get_type() {
    return ADDER;
}

int ohpc::Subber::get_type() {
    return SUB;
}

int ohpc::Diver::get_type() {
    return DIV;
}

int ohpc::Muller::get_type() {
    return MUL;
}