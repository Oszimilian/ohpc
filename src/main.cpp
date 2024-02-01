#include <iostream>
#include <chrono>


#include "ohpc.h"

using namespace ohpc;




int main() {

    std::cout << "Input: ";
    std::string str;
    std::getline(std::cin, str);
    std::cout << std::endl;

    try {

        ohpc::Ohpc solver;
        //solver.debug("debug.txt");
        auto start = std::chrono::steady_clock::now();
        auto sol = solver.calc(str);
        auto end = std::chrono::steady_clock::now();
        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds> (end - start).count() << std::endl;

        std::cout << sol << std::endl;

    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Ende" << std::endl;
    return 0;
}
