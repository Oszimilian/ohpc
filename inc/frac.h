//
// Created by maximilian-tuxedo on 27.12.2023.
//

#ifndef OHPC_FRAC_H
#define OHPC_FRAC_H

#include "tvec.h"
#include "num.h"
#include "element.h"

namespace ohpc {
    class Frac : public element{
    public:
        Frac();
        Frac(int numerator, int denumerator);

        Frac& operator=(const Num& other);
        int get_type() override;
        int get_prio() override;


        friend std::ostream& operator<<(std::ostream& stream, Frac& val);
        friend class Num;

        void simplify();

        Frac& operator+(const Frac& other);
        Frac& operator-(const Frac& other);
        Frac& operator*(const Frac& other);
        Frac& operator/(const Frac& other);

    public:
        int numerator;
        int denumerator;
    };

    std::ostream& operator<<(std::ostream& stream, Frac& val);

}

#endif //OHPC_FRAC_H
