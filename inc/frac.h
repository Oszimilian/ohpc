//
// Created by maximilian-tuxedo on 27.12.2023.
//

#ifndef OHPC_FRAC_H
#define OHPC_FRAC_H

#include "tvec.h"
#include "num.h"

namespace ohpc {
    class Frac {
    public:
        Frac();
        Frac(int numerator, int denumerator);

        Frac& operator=(const Num& other);
        void doSomething();


        friend std::ostream& operator<<(std::ostream& stream, Frac& val);
        friend class Num;

    public:
        int numerator;
        int denumerator;
    };

    std::ostream& operator<<(std::ostream& stream, Frac& val);

}

#endif //OHPC_FRAC_H
