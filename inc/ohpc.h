//
// Created by maxim on 13.01.2024.
//

#ifndef OHPC_OHPC_H
#define OHPC_OHPC_H

#include <string>
#include <iostream>
#include <fstream>

#include "frac.h"
#include "num.h"
#include "element.h"
#include "operators.h"
#include "Equation.h"
#include "Shuntingyard.h"
#include <tuple>

namespace ohpc {
    class Ohpc {
    public:
        Ohpc() = default;
        ~Ohpc();
        void debug(std::string path);
        std::tuple<Num, Frac> calc(const std::string& str);

    private:
        bool dbg = false;
        std::streambuf* old_stream;
        std::shared_ptr<std::ofstream> file;
    };

    std::ostream& operator<<(std::ostream& stream, std::tuple<Num, Frac>& other);
}


#endif //OHPC_OHPC_H
