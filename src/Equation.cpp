//
// Created by maximilian-tuxedo on 01.01.2024.
//

#include "Equation.h"
#include <sstream>
#include <iterator>
#include <iostream>
#include <algorithm>

#include "num.h"
#include "frac.h"
#include "operators.h"

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

ohpc::Equation& ohpc::Equation::operator=(const std::list<std::shared_ptr<element>> &other) {
    equation = other;
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
                equation.push_back(get_operator_element(i));
                break;

            case number_:
                equation.push_back(get_number_element(i));
                break;

            case braket_open_:
                equation.push_back(std::make_shared<ohpc::OpenBraket>());
                break;

            case braket_close_:
                equation.push_back(std::make_shared<ohpc::CloseBraket>());
                break;

            case error_:
                std::cout << i << " => Not valid" << std::endl;
                exit(EXIT_FAILURE);
                return;
                break;

            default : break;
        }
    }
}

int ohpc::Equation::get_element_type(const std::string &str) {

    if(str[0] == '(') return braket_open_;
    else if (str[0] == ')') return braket_close_;

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

void ohpc::Equation::change_stream_behaviour(std::string str) {
    stream_behaviour = str;
}

std::ostream& ohpc::operator<<(std::ostream &stream, ohpc::Equation &eq) {

    for (const auto& i : eq.equation) {
        switch (i->get_type()) {
            case ADDER:
                stream << " + " << eq.stream_behaviour;
                break;

            case SUB:
                stream << " - " << eq.stream_behaviour;
                break;

            case DIV:
                stream << " / " << eq.stream_behaviour;
                break;

            case MUL:
                stream << " * " << eq.stream_behaviour;
                break;

            case FRAC:
                auto* frac = dynamic_cast<ohpc::Frac*>(i.get());
                ohpc::Num n;
                n = *frac;
                stream << " " << n << " " << eq.stream_behaviour;
                break;

        }
    }

    return stream;
}

std::shared_ptr<ohpc::element> ohpc::Equation::get_operator_element(const std::string &op) {

    switch(op[0]) {
        case '+' : return std::make_shared<ohpc::Adder>();
        case '-' : return std::make_shared<ohpc::Subber>();
        case '/' : return std::make_shared<ohpc::Diver>();
        case '*' : return std::make_shared<ohpc::Muller>();
        default: std::cout << "Cant extract element from: " << op[0] << std::endl; break;
    }

    return nullptr;
}

std::shared_ptr<ohpc::element> ohpc::Equation::get_number_element(const std::string &op) {
    auto point = std::find_if(op.begin(), op.end(), [](char c) {return c == '.';});


    ohpc::Tvec nl;
    ohpc::Tvec nr;

    std::string left(op.begin(), point);

    nl = left;


    if (point != op.end()) {
        std::string right(point + 1, op.end());
        nr = right;
    } else {
        nr = 0;
    }
    ohpc::Num number(PLUS, nl, nr);
    std::shared_ptr<ohpc::Frac> fraction = std::make_shared<ohpc::Frac>();

    *fraction = number;

    return fraction;
}

