//
// Created by maximilian-tuxedo on 27.12.2023.
//

#ifndef OHPC_NUM_H
#define OHPC_NUM_H

#include "tvec.h"



namespace ohpc {
    class Frac;

    class Num {
    public:
        Num();
        Num(bool sign, Tvec& left, Tvec& right);

        const Tvec& get_right() const;
        const Tvec& get_left() const;
        const bool get_sign() const;
        std::size_t decimal_places() const;

        Num& operator=(Frac& other);


        friend std::ostream& operator<<(std::ostream& stream, Num& val);

    private:
        Tvec left;
        Tvec right;
        bool sign = PLUS;

        int p_count = 10;
    };

    std::ostream& operator<<(std::ostream& stream, Num& val);
}

#endif //OHPC_NUM_H
