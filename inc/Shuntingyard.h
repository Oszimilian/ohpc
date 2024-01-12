//
// Created by maximilian-tuxedo on 07.01.2024.
//

#ifndef OHPC_SHUNTINGYARD_H
#define OHPC_SHUNTINGYARD_H

#include "Equation.h"
#include <list>
#include <stack>
#include <map>

namespace ohpc {
    class Shuntingyard {
    public:
        Shuntingyard();
        Shuntingyard(const Equation& others);


        Shuntingyard& operator=(const Equation& others);

    private:

        static const int id_numeric = 0;
        static const int id_operator = 1;

        void process(const Equation& others);


        std::map<int,int> type_prio;
        Equation infix;
    };
}

#endif //OHPC_SHUNTINGYARD_H
