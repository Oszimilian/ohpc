//
// Created by maximilian-tuxedo on 01.01.2024.
//

#ifndef OHPC_EQUATION_H
#define OHPC_EQUATION_H

#include "element.h"
#include <list>
#include <string>

namespace ohpc {
    class Equation {
    public:
        Equation();
        Equation(const std::string& str);

        Equation& operator=(const std::string& str);
    private:
        void init();
        void process_input_string(const std::string& str);

        constexpr static int error_ = -1;
        constexpr static int operator_ = 0;
        constexpr static int number_ = 1;
        constexpr static int braket_ = 2;

        int get_element_type(const std::string& str);

        std::list<ohpc::element*> equation;

        std::list<std::string> possible_brakets;
        std::list<std::string> possible_numbers;
        std::list<std::string> possible_operator;


    };
}

#endif //OHPC_EQUATION_H
