//
// Created by maximilian-tuxedo on 27.12.2023.
//

#include "frac.h"
#include <math.h>

ohpc::Frac::Frac() : numerator(1), denumerator(1) {

}

ohpc::Frac::Frac(int numerator, int denumerator) : numerator(numerator), denumerator(denumerator) {

}

ohpc::Frac& ohpc::Frac::operator=(const ohpc::Num &other) {

    denumerator = (int)std::pow(10, other.decimal_places());
    Tvec temp;
    temp += other.get_left();
    temp += other.get_right();
    temp.clean();

    numerator = 0;
    auto it = temp.get().rbegin();
    for (int i = 0; it != temp.get().rend(); i++, it++) {
        numerator += (int)std::pow(10, i) * *it;
    }

    return *this;
}

std::ostream& ohpc::operator<<(std::ostream &stream, ohpc::Frac &val) {
    stream << val.numerator << "/" << val.denumerator;
    return stream;
}