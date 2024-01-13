#include <iostream>


#include "ohpc.h"

using namespace ohpc;




int main() {

    std::cout << "Input: ";
    std::string str;
    std::getline(std::cin, str);
    std::cout << std::endl;

    try {

        ohpc::Ohpc solver;
        solver.debug("debug.txt");
        auto sol = solver.calc(str);

        std::cout << sol << std::endl;

    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Ende" << std::endl;
    return 0;
}
