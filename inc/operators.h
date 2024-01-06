//
// Created by maximilian-tuxedo on 27.12.2023.
//

#ifndef OHPC_OPERATORS_H
#define OHPC_OPERATORS_H

#include "element.h"

namespace ohpc {
    class Adder : public element{
        int get_type() override;
    };

    class Subber : public element {
        int get_type() override;
    };

    class Diver : public element {
        int get_type() override;
    };

    class Muller : public element {
        int get_type() override;
    };
}

#endif //OHPC_OPERATORS_H
