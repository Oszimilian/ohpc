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
    /**
     * @brief This is the base class of oszimilians high precission calculator
     */
    class Ohpc {
    public:
        Ohpc() = default;
        ~Ohpc();

        /**
         * @brief function to pass the output of cout to a debug file
         * @param path path of the debug file
         */
        void debug(std::string path);

        /**
         * @brief functione returns the solution of the stringequations in num and frac style
         * @param str equation
         * @return solution in num and frac style
         */
        std::tuple<Num, Frac> calc(const std::string& str);

    private:

        /**
         * @brief flag indicates if the cout stream is passed to a file or to the terminal
         */
        bool dbg = false;

        /**
         * @brief pointer to the std::cout-stream to change it after descriptor was called
         */
        std::streambuf* old_stream;

        /**
         * @brief fileobject for debugoutput
         */
        std::shared_ptr<std::ofstream> file;
    };

    /**
     * @brief operator to print the solution tuple containing a num and frac style solution
     * @param stream
     * @param other tuple which contains the solution
     * @return stream
     */
    std::ostream& operator<<(std::ostream& stream, std::tuple<Num, Frac>& other);
}


#endif //OHPC_OHPC_H
