#ifndef CALCULATOR_VARIABLE_H
#define CALCULATOR_VARIABLE_H
#include "../../lib1/std_lib_facilities.h"
struct Variable
{
  string name;
  double value;

  bool is_const;

  Variable(string n, double v, bool c) : name{n}, value{v}, is_const(c) {}
};

class Symbol_table
{
public:
  vector<Variable> var_table;
  Symbol_table(){};
  double get (string s);
  double set (string s, double d);
  bool is_declared (string s);
  double define (string var, double val, bool c);

  bool check_const (string s);
};
extern Symbol_table st;
#endif