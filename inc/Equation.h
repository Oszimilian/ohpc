//
// Created by maximilian-tuxedo on 01.01.2024.
//

#ifndef OHPC_EQUATION_H
#define OHPC_EQUATION_H

#include "element.h"
#include <list>
#include <string>
#include <memory>

namespace ohpc {
    class Equation {
    public:
        Equation();
        Equation(const std::string& str);

        Equation& operator=(const std::string& str);

        friend std::ostream& operator<<(std::ostream& stream, Equation& eq);
        void change_stream_behaviour(std::string str);
    private:
        std::string stream_behaviour = "";
        void init();
        void process_input_string(const std::string& str);

        constexpr static int error_ = -1;
        constexpr static int operator_ = 0;
        constexpr static int number_ = 1;
        constexpr static int braket_ = 2;

        int get_element_type(const std::string& str);
        static std::shared_ptr<element> get_operator_element(const std::string& op);
        static std::shared_ptr<element> get_number_element(const std::string& op);


        std::list<std::shared_ptr<element>> equation;

        std::list<std::string> possible_brakets;
        std::list<std::string> possible_numbers;
        std::list<std::string> possible_operator;


    };

    std::ostream& operator<<(std::ostream& stream, Equation& eq);
}

#endif //OHPC_EQUATION_H
