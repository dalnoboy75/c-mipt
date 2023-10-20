#ifndef CALCULATOR_CALCULATING_H
#define CALCULATOR_CALCULATING_H
#include "token.h"
#include "../../lib1/std_lib_facilities.h"
double primary();

double underterm();

double term();

double expression();

double declaration(bool c);

double change_value(Token t);

double statement();

void clean_up_mess();

void user_help();

void calculate();
#endif