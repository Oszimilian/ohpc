#include <iostream>


#include "ohpc.h"

using namespace ohpc;




int main() {

    try {

        //std::string str;
        //std::getline(std::cin, str);
        ohpc::Equation e;
        e.change_stream_behaviour("\n");

        //e = str;
        e = "5 + 2 ( 2 - 0.6 )";
        std::cout << e << std::endl;
        ohpc::Shuntingyard s;
        s = e;
        auto sol = s.solve();
        ohpc::Num num;
        num = sol;
        std::cout << sol << " = " << num << std::endl;
    } catch (ohpc::Input_Error& e) {
        std::cerr << e.what() << std::endl;
    } catch (ohpc::Conversion_Error& e) {
        std::cerr << e.what() << std::endl;
    } catch (ohpc::Solving_Error& e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}
