//
// Created by maximilian-tuxedo on 27.12.2023.
//

#ifndef OHPC_ELEMENT_H
#define OHPC_ELEMENT_H

#include "myexceptions.h"

namespace ohpc {


    class element {
    public:
        virtual int get_type() = 0;
        virtual int get_prio() = 0;
    };
}

#endif //OHPC_ELEMENT_H
