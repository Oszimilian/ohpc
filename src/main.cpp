#include <iostream>


#include "frac.h"
#include "num.h"
#include "element.h"
#include "operators.h"
#include "Equation.h"
#include "Shuntingyard.h"

using namespace ohpc;

void test1() {
    std::list<ohpc::element*> equation;

    Tvec v {1,2};
    Tvec b {0,4,6,0};

    Num n(PLUS, v,b);
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

}

void test2() {
    Frac f1(4, 9);
    Frac f2(11,3);

    Frac z;
    z = f1 / f2;

    Num n;
    n = z;
    z.simplify();
    std::cout << z << " " << n << std::endl;
}

int main() {

    std::string str;
    std::getline(std::cin, str);
    ohpc::Equation e;
    e.change_stream_behaviour("\n");

    e = str;
    std::cout << e << std::endl;
    ohpc::Shuntingyard s;
    s = e;


    return 0;
}
