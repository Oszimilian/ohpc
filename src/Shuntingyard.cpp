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

std::shared_ptr<ohpc::element> ohpc::Shuntingyard::solve_part(std::shared_ptr<ohpc::element> &l,
                                                              std::shared_ptr<ohpc::element> &m,
                                                              std::shared_ptr<ohpc::element> &r) {
    std::shared_ptr<ohpc::element> solution;
    ohpc::Frac f;
    auto* l_tmp = dynamic_cast<ohpc::Frac*>(l.get());
    auto* m_tmp = dynamic_cast<ohpc::Frac*>(m.get());

    if (l_tmp != nullptr && m_tmp != nullptr) {
        switch (r->get_type()) {
            case ADDER:
                std::cout << *l_tmp << " + " << *m_tmp << " = ";
                f = *l_tmp + *m_tmp;
                std::cout << f << std::endl;
                solution = std::make_shared<ohpc::Frac>(f);
                break;

            case SUB:
                std::cout << *l_tmp << " - " << *m_tmp << " = ";
                f = *l_tmp - *m_tmp;
                std::cout << f << std::endl;
                solution = std::make_shared<ohpc::Frac>(f);
                break;

            case DIV:
                std::cout << *l_tmp << " / " << *m_tmp << " = ";
                f = *l_tmp / *m_tmp;
                std::cout << f << std::endl;
                solution = std::make_shared<ohpc::Frac>(f);
                break;

            case MUL:
                std::cout << *l_tmp << " * " << *m_tmp << " = ";
                f = *l_tmp * *m_tmp;
                std::cout << f << std::endl;
                solution = std::make_shared<ohpc::Frac>(f);
                break;

            default:
                throw Input_Error("No valid Input!");
        }
    } else {
        throw Solving_Error("Fractions are NULL");
    }

    return solution;
}

ohpc::Frac ohpc::Shuntingyard::solve() {


    while (infix.equation.size() > 1) {
        bool found = false;
        auto it = infix.equation.begin();
        int j = 0;

        for (const auto& i : infix.equation) {

            switch (i->get_type()) {
                case ADDER:
                case SUB:
                case DIV:
                case MUL:
                    found = true;
                    break;

                default: break;
            }
            if (found) break;
            it++;
            j++;
        }

        if (found) {
            auto r = *it;
            auto m = *(--it);
            auto l = *(--it);

            auto sol = solve_part(l,m,r);
            for (int i = 0; i < 3; i++) {
                infix.equation.erase(it++);
            }

            infix.equation.insert(std::next(infix.equation.begin(), j - 2), sol);

            std::cout << infix << std::endl << std::endl;
        } else {
            throw Solving_Error("Cant solve equation. Maybe there is a braket with no previous operator!");
        }

    }

    ohpc::Frac *f = dynamic_cast<ohpc::Frac*>(infix.equation.begin()->get());
    if(f != nullptr) {
        return *f;
    } else {
        exit(EXIT_FAILURE);
    }
}