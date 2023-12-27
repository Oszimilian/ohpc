#include <iostream>


#include "frac.h"
#include "num.h"

using namespace ohpc;



int main() {
    Tvec v {1,2};
    Tvec b {0,4,6,0};

    Num n(v,b);
    std::cout << "Numer: " << n << std::endl;

    Frac f;
    f = n;

    std::cout << "Fraction: " << f << std::endl;

    Num n1;
    n1 = f;

    std::cout << "Number: " << n1 << std::endl;


    return 0;
}
