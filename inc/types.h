//
// Created by maximilian-tuxedo on 26.12.2023.
//

#ifndef OHPC_TYPES_H
#define OHPC_TYPES_H

#include <list>

typedef std::list<int> vec_t;


const int FRAC = 0;
const int FRAC_PRIO = -1;

const int ADDER = 1;
const int ADDER_PRIO = 0;

const int SUB = 2;
const int SUB_PRIO = 0;

const int DIV = 3;
const int DIV_PRIO = 1;

const int MUL = 4;
const int MUL_PRIO = 1;

const int BRAK_OPEN = 5;
const int BRAK_OPEN_PRIO = -1;

const int BRAK_CLOSE = 6;
const int BRAK_CLOSE_PRIO = -1;

const bool PLUS = true;
const bool MINUS = false;

#endif //OHPC_TYPES_H
