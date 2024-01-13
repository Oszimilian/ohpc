//
// Created by maxim on 13.01.2024.
//
#include <ctime>
#include "ohpc.h"

ohpc::Ohpc::~Ohpc() {
    if (dbg) {
        std::cout.rdbuf(old_stream);
    }
    std::cout << "Test" << std::endl;
}

std::tuple<ohpc::Num, ohpc::Frac> ohpc::Ohpc::calc(const std::string &str) {
    ohpc::Equation equation;
    equation.change_stream_behaviour("\n");
    equation = str;

    ohpc::Shuntingyard sy = equation;

    ohpc::Frac solution_frac = sy.solve();
    ohpc::Num solution_num;
    solution_num = solution_frac;

    return std::make_tuple(solution_num, solution_frac);
}

std::ostream& ohpc::operator<<(std::ostream &stream, std::tuple<Num, Frac> &other) {
    auto num = std::get<0>(other);
    auto frac = std::get<1>(other);

    frac.simplify();

    stream << num << " | " << frac;
    return stream;
}

void ohpc::Ohpc::debug(std::string path) {
    dbg = true;
    file = std::make_shared<std::ofstream>(path, std::ofstream::app);
    if (file) {
        old_stream = std::cout.rdbuf();
        std::cout.rdbuf(file->rdbuf());

        time_t now = time(NULL);
        struct tm localTime;
        localtime_s(&localTime, &now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);

        std::cout << std::endl << buffer << std::endl;

    } else {
        throw std::runtime_error("Can't open debug file!");
    }
}