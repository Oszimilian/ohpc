//
// Created by maximilian-tuxedo on 27.12.2023.
//

#include "frac.h"
#include <math.h>
#include "types.h"

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

    if(other.get_sign() == MINUS) {
        denumerator *= -1;
    }

    return *this;
}

std::ostream& ohpc::operator<<(std::ostream &stream, ohpc::Frac &val) {
    stream << val.numerator << "/" << val.denumerator;
    return stream;
}

int ohpc::Frac::get_type() {
    return FRAC;
}

void ohpc::Frac::simplify() {
    int highest_part = (numerator > denumerator) ? numerator : denumerator;
    bool sign = PLUS;
    if(numerator < 0) {
        sign = MINUS;
        numerator *= -1;
    }

    for (int i = 2; i < highest_part; i++) {
        while(((numerator % i) == 0) && ((denumerator % i) == 0)) {
            numerator /= i;
            denumerator /= i;
        }
    }

    if (sign == MINUS) {
        numerator *= -1;
    }
}

ohpc::Frac& ohpc::Frac::operator+(const ohpc::Frac &other) {
    if (&other != this) {
        numerator = other.denumerator * numerator + denumerator * other.numerator;
        denumerator = denumerator * other.denumerator;
        return *this;
    } else {
        other;
    }
}

ohpc::Frac& ohpc::Frac::operator-(const ohpc::Frac &other) {
    if (&other != this) {
        numerator = other.denumerator * numerator - denumerator * other.numerator;
        denumerator = denumerator * other.denumerator;
        return *this;
    } else {
        other;
    }
}

ohpc::Frac& ohpc::Frac::operator*(const ohpc::Frac &other) {
    if(&other != this) {
        numerator *= other.numerator;
        denumerator *= other.denumerator;
        return *this;
    } else {
        other;
    }
}

ohpc::Frac& ohpc::Frac::operator/(const ohpc::Frac &other) {
    if(&other != this) {
        numerator *= other.denumerator;
        denumerator *= other.numerator;
        return *this;
    } else {
        other;
    }
}