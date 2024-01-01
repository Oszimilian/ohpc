//
// Created by maximilian-tuxedo on 01.01.2024.
//

#include "Equation.h"
#include <sstream>
#include <iterator>
#include <iostream>
#include <algorithm>

ohpc::Equation::Equation() : equation(){
    init();
}

ohpc::Equation::Equation(const std::string& str) : equation(){
    init();
    process_input_string(str);
}

ohpc::Equation& ohpc::Equation::operator=(const std::string &str) {
    process_input_string(str);

    return *this;
}

void ohpc::Equation::process_input_string(const std::string &str) {
    std::list<std::string> equation_parts;

    std::istringstream iss;
    iss.str(str);
    std::istream_iterator<std::string> it = std::istream_iterator<std::string>(iss);
    std::istream_iterator<std::string> it_end;

    while(it_end != it) {
        equation_parts.push_back(*it++);
    }

    for (const auto& i : equation_parts) {
        switch (get_element_type(i)) {
            case operator_:
                std::cout << i << " => Operator" << std::endl;
                break;

            case number_:
                std::cout << i << " => Number" << std::endl;
                break;

            case braket_:
                std::cout << i << " => Braket" << std::endl;
                break;

            case error_:
                std::cout << i << " => Not valid" << std::endl;
                break;

            default : break;
        }
    }
}

int ohpc::Equation::get_element_type(const std::string &str) {

    for (const auto& i : possible_brakets) {
        if(i == str) return braket_;
    }

    for (const auto& i : possible_operator) {
        if(i == str) return operator_;
    }

    for (const auto& i : str) {
        auto it = std::find_if(possible_numbers.begin(), possible_numbers.end(), [&i](std::string str) {
            return (i == str[0]);
        });
        if(it == possible_numbers.end()) return error_;
    }
    return number_;
}

void ohpc::Equation::init() {
    //Brakets
    possible_brakets.emplace_back("(");
    possible_brakets.emplace_back(")");
    possible_brakets.emplace_back("[");
    possible_brakets.emplace_back("]");
    possible_brakets.emplace_back("{");
    possible_brakets.emplace_back("}");

    //Numbers
    possible_numbers.emplace_back("0");
    possible_numbers.emplace_back("1");
    possible_numbers.emplace_back("2");
    possible_numbers.emplace_back("3");
    possible_numbers.emplace_back("4");
    possible_numbers.emplace_back("5");
    possible_numbers.emplace_back("6");
    possible_numbers.emplace_back("7");
    possible_numbers.emplace_back("8");
    possible_numbers.emplace_back("9");

    //Notations
    possible_numbers.emplace_back(".");
    possible_numbers.emplace_back("^");

    //operator
    possible_operator.emplace_back("+");
    possible_operator.emplace_back("-");
    possible_operator.emplace_back("*");
    possible_operator.emplace_back("/");

}