//
// Created by maximilian-tuxedo on 27.12.2023.
//

#include "num.h"
#include "frac.h"

ohpc::Num::Num() : left(), right(){

}

ohpc::Num::Num(bool sign, ohpc::Tvec& left, ohpc::Tvec& right) : sign(sign), left(left), right(right){

}

std::ostream& ohpc::operator<<(std::ostream& stream, ohpc::Num& val) {
    stream << (val.get_sign()? "":"-")<<val.left << "." << val.right;
    return stream;
}

std::size_t ohpc::Num::decimal_places() const {
    Tvec temp = this->right;
    temp.clean();
    return temp.len();
}

const ohpc::Tvec& ohpc::Num::get_left() const {
    return this->left;
}

const ohpc::Tvec& ohpc::Num::get_right() const {
    return this->right;
}

const bool ohpc::Num::get_sign() const {
    return this->sign;
}

ohpc::Num& ohpc::Num::operator=(ohpc::Frac &other) {

    this->sign = (other.numerator >= 0);
    int temp_sign = this->sign ? 1 : -1;
    this->left = (temp_sign * other.numerator) / other.denumerator;
    int i = (temp_sign * other.numerator) % other.denumerator;

    vec_t vec;

    int count = 0;
    if(i > 0) {
         do{
            if(i > other.denumerator) {
                vec.push_back(i / other.denumerator);
                i %= other.denumerator;
            } else {
                vec.push_back(0);
            }
            i *= 10;
        }while(i > 0 && ++count < this->p_count);
         vec.pop_front();
    } else {
        vec.push_back(0);
    }

    this->right = vec;

    return *this;
}

