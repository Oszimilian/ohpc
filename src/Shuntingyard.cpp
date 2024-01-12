//
// Created by maximilian-tuxedo on 07.01.2024.
//

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
                while(stack.top()->get_prio() > i->get_prio() && stack.top())
                break;

            case BRAK_OPEN:
                //do Something
                break;

            default: break;
        }
    }
}