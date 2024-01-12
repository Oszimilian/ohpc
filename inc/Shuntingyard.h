//
// Created by maximilian-tuxedo on 07.01.2024.
//

#ifndef OHPC_SHUNTINGYARD_H
#define OHPC_SHUNTINGYARD_H

#include "Equation.h"
#include "frac.h"
#include <list>
#include <stack>
#include <map>

namespace ohpc {
    class Shuntingyard {
    public:
        Shuntingyard();
        Shuntingyard(const Equation& others);


        Shuntingyard& operator=(const Equation& others);

        Frac solve();
    private:

        static const int id_numeric = 0;
        static const int id_operator = 1;

        void process(const Equation& others);
        std::shared_ptr<element> solve_part(std::shared_ptr<element>& l,
                                            std::shared_ptr<element>& m,
                                            std::shared_ptr<element>& r);

        std::map<int,int> type_prio;
        Equation infix;
    };
}

#endif //OHPC_SHUNTINGYARD_H
