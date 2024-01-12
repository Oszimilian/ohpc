//
// Created by maximilian-tuxedo on 27.12.2023.
//

#ifndef OHPC_OPERATORS_H
#define OHPC_OPERATORS_H

#include "element.h"

namespace ohpc {
    class Adder : public element{
        int get_type() override;
        int get_prio() override;
    };

    class Subber : public element {
        int get_type() override;
        int get_prio() override;
    };

    class Diver : public element {
        int get_type() override;
        int get_prio() override;
    };

    class Muller : public element {
        int get_type() override;
        int get_prio() override;
    };

    class OpenBraket : public element {
        int get_type() override;
        int get_prio() override;
    };

    class CloseBraket : public element {
        int get_type() override;
        int get_prio() override;
    };
}

#endif //OHPC_OPERATORS_H
