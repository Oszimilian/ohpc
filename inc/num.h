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
        Num(Tvec& left, Tvec& right);

        const Tvec& get_right() const;
        const Tvec& get_left() const;
        std::size_t decimal_places() const;

        Num& operator=(Frac& other);


        friend std::ostream& operator<<(std::ostream& stream, Num& val);

    private:
        Tvec left;
        Tvec right;
    };

    std::ostream& operator<<(std::ostream& stream, Num& val);
}

#endif //OHPC_NUM_H
