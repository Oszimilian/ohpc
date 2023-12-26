#include <iostream>
#include "tvec.h"

using namespace ohpc;



int main() {
    Tvec v {1,2,3,4};
    Tvec b {5,6,7,8, 2, 3};

    v.match(b);
    std::cout << b << std::endl;
    std::cout << v << std::endl;

    v.clean();

    std::cout << v.sum() << std::endl;
    return 0;
}
