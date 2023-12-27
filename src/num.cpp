//
// Created by maximilian-tuxedo on 27.12.2023.
//

#include "num.h"
#include "frac.h"

ohpc::Num::Num() : left(), right(){

}

ohpc::Num::Num(ohpc::Tvec& left, ohpc::Tvec& right) : left(left), right(right){

}

std::ostream& ohpc::operator<<(std::ostream& stream, ohpc::Num& val) {
    stream << val.left << "." << val.right;
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

ohpc::Num& ohpc::Num::operator=(ohpc::Frac &other) {
    this->left = other.numerator / other.denumerator;

    int i = other.numerator % other.denumerator;

    vec_t vec;

    if(i > 0) {
         do{
            if(i > other.denumerator) {
                vec.push_back(i / other.denumerator);
                i %= other.denumerator;
            } else {
                vec.push_back(0);
            }
            i *= 10;
        }while(i > 0);
         vec.pop_front();
    } else {
        vec.push_back(0);
    }

    this->right = vec;

    return *this;
}

