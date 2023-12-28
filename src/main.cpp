#include <iostream>


#include "frac.h"
#include "num.h"
#include "element.h"
#include "adder.h"

using namespace ohpc;



int main() {

    std::list<ohpc::element*> equation;

    Tvec v {1,2};
    Tvec b {0,4,6,0};

    Num n(v,b);
    std::cout << "Input Number: " << n << std::endl;

    Frac *t1 = new Frac;
    *t1 = n;
    std::cout << "Input Fraction: " << *t1 << std::endl;

    Adder *a1 = new Adder;


    equation.push_back(t1);
    equation.push_back(a1);

    auto it = equation.begin();

    if (ohpc::Frac *fracPtr = dynamic_cast<ohpc::Frac*>(*it)) {

        std::cout << *fracPtr << std::endl;

    }







    return 0;
}
