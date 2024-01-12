//
// Created by maximilian-tuxedo on 28.12.2023.
//

#include "operators.h"
#include "types.h"

int ohpc::Adder::get_type() {return ADDER;}
int ohpc::Adder::get_prio() {return ADDER_PRIO;}

int ohpc::Subber::get_type() {return SUB;}
int ohpc::Subber::get_prio() {return SUB_PRIO;}

int ohpc::Diver::get_type() {return DIV;}
int ohpc::Diver::get_prio() {return DIV_PRIO;}

int ohpc::Muller::get_type() {return MUL;}
int ohpc::Muller::get_prio() {return MUL_PRIO;}

int ohpc::OpenBraket::get_type() {return BRAK_OPEN;}
int ohpc::OpenBraket::get_prio() {return BRAK_OPEN_PRIO;}

int ohpc::CloseBraket::get_type() {return BRAK_CLOSE;}
int ohpc::CloseBraket::get_prio() {return BRAK_CLOSE_PRIO;}