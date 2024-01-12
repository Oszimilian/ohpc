//
// Created by maximilian-tuxedo on 07.01.2024.
//

#include <iostream>
#include "types.h"
#include "Shuntingyard.h"

ohpc::Shuntingyard::Shuntingyard() : infix(), type_prio(){

}

ohpc::Shuntingyard::Shuntingyard(const ohpc::Equation &others) : infix(), type_prio() {
    process(others);
}



ohpc::Shuntingyard& ohpc::Shuntingyard::operator=(const ohpc::Equation &others) {
    process(others);
    return *this;
}

void ohpc::Shuntingyard::process(const ohpc::Equation& other) {
    std::list<std::shared_ptr<ohpc::element>> out;
    std::stack<std::shared_ptr<ohpc::element>> stack;

    for (const auto& i : other.equation) {
        switch (i->get_type()) {
            case FRAC:
                out.push_back(i);
                break;

            case ADDER:
            case SUB:
            case DIV:
            case MUL:
                while(  !stack.empty() &&
                        stack.top()->get_type() != FRAC &&
                        stack.top()->get_type() != BRAK_OPEN &&
                        stack.top()->get_type() != BRAK_CLOSE &&
                        stack.top()->get_prio() > i->get_prio()) {
                    out.push_back(stack.top());
                    stack.pop();
                }
                stack.push(i);
                break;

            case BRAK_OPEN:
                stack.push(i);
                break;

            case BRAK_CLOSE:
                while(stack.top()->get_type() != BRAK_OPEN) {
                    out.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();
                break;


            default: break;
        }
    }

    while(!stack.empty()) {
        out.push_back(stack.top());
        stack.pop();
    }

    infix = out;
    std::cout << infix << std::endl;
}