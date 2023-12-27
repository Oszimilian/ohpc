//
// Created by maximilian-tuxedo on 26.12.2023.
//

#ifndef OHPC_TVEC_H
#define OHPC_TVEC_H

#include <list>
#include <iostream>

#include "types.h"

namespace ohpc {
    class Tvec {
    public:
        Tvec();
        Tvec(std::initializer_list<int> values);


        const vec_t& get() const;
        std::size_t len() const;
        vec_t& set(std::list<int>& other);
        int sum() const;

        vec_t& append_zeros(int count);
        vec_t& match(const Tvec& other);
        vec_t& clean();


        Tvec& operator=(const Tvec& other);
        Tvec& operator=(int val);
        Tvec& operator+=(const Tvec& other);
        Tvec& operator=(vec_t& other);

        friend std::ostream& operator<<(std::ostream& stream, Tvec& val);
    private:
        std::list<int> val;
    };

    std::ostream& operator<<(std::ostream& stream, Tvec& val);
}



#endif //OHPC_TVEC_H
