//
// Created by maximilian-tuxedo on 26.12.2023.
//

#include "tvec.h"
#include <algorithm>


ohpc::Tvec::Tvec() : val(){

}

ohpc::Tvec::Tvec(std::initializer_list<int> values) : val(values.begin(), values.end()){

}

const vec_t& ohpc::Tvec::get() const{
    return this->val;
}

size_t ohpc::Tvec::len() const{
    return this->val.size();
}

vec_t& ohpc::Tvec::set(std::list<int> &other) {
    this->val = other;
    return this->val;
}

int ohpc::Tvec::sum() const {
    int sum = 0;
    std::for_each(this->val.begin(), this->val.end(), [&sum](int i) {sum += i;});
    return sum;
}

vec_t& ohpc::Tvec::append_zeros(int count) {
    for (int i = 0; i < count; i++) {
        this->val.push_back(0);
    }
    return this->val;
}

vec_t& ohpc::Tvec::match(const ohpc::Tvec &other) {
    if(other.len() > this->len()) {
        append_zeros(other.len() - this->len());
    }

    return this->val;
}

vec_t& ohpc::Tvec::clean() {
    auto it = std::find_if(this->val.rbegin(), this->val.rend(), [](int i ){
        return (i != 0);
    });

    val.erase(it.base(), val.end());

    return this->val;
}

ohpc::Tvec& ohpc::Tvec::operator=(const ohpc::Tvec &other) {
    if(this != &other) {
        this->val = other.val;
    }
    return *this;
}

ohpc::Tvec& ohpc::Tvec::operator+=(const ohpc::Tvec &other) {
    if(this != &other) {
        for(const auto &i : other.val) {
            this->val.push_back(i);
        }
    }
    return *this;
}

ohpc::Tvec& ohpc::Tvec::operator=(int val) {
    if(val == 0) this->val.push_back(0);
    while(val > 0) {
        this->val.push_front(val % 10);
        val /= 10;
    }
    return *this;
}

ohpc::Tvec& ohpc::Tvec::operator=(vec_t& other) {
    this->val = other;
    return *this;
}

ohpc::Tvec& ohpc::Tvec::operator=(const std::string& vec) {
    auto it = std::find_if(vec.begin(),vec.end(), [](char c){return (c < '0' || c > '9' || c != '\0');});
    if(it != vec.end()) {
        for (const auto& i : vec) {
            val.push_back((int)(i - '0'));
        }
    } else {
        std::cout << "Vector is not only number: " << vec << std::endl;
    }

    return *this;
}

std::ostream& ohpc::operator<<(std::ostream& stream, ohpc::Tvec& val) {
    for (auto it = val.get().begin(); it != val.get().end(); it++) {
        auto temp = it;
        stream << *it;
        if(++temp !=  val.get().end()) {
            stream << "";
        }
    }

    return stream;
}







