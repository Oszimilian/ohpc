//
// Created by maxim on 13.01.2024.
//

#ifndef OHPC_MYEXCEPTIONS_H
#define OHPC_MYEXCEPTIONS_H

#include <exception>
#include <string>
#include <utility>

namespace ohpc {
    struct Input_Error : public std::exception {
        std::string msg;

        explicit Input_Error(std::string  msg) : msg(std::move(msg)) {}
        Input_Error() : msg("default") {}

        const char* what() const noexcept override {
            static std::string temp;
            temp = "INPUT ERROR: \n";
            temp += "Reason: ";
            temp += msg;
            return temp.c_str();
        }
    };

    struct Conversion_Error : public std::exception {
        std::string msg;
        explicit Conversion_Error(std::string msg) : msg(std::move(msg)) {}
        Conversion_Error() : msg("default") {}

        const char* what() const noexcept override {
            static std::string temp;
            temp = "CONVERSION ERROR: \n";
            temp += "Reason: ";
            temp += msg;
            return temp.c_str();
        }
    };

    struct Solving_Error : public std::exception {
        std::string msg;
        explicit Solving_Error(std::string msg) : msg(std::move(msg)) {}
        Solving_Error() : msg("default") {}

        const char* what() const noexcept override {
            static std::string temp;
            temp = "SOLVING ERROR: \n";
            temp += "Reason: ";
            temp += msg;
            return temp.c_str();
        }
    };
}

#endif //OHPC_MYEXCEPTIONS_H
