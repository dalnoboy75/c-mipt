#ifndef CALCULATOR_TOKEN_H
#define CALCULATOR_TOKEN_H
#include "../../lib1/std_lib_facilities.h"
struct Token
{
  char kind;
  double value;
  string name;

  Token(char ch) : kind{ch}, value{0} {}

  Token(char ch, double val) : kind{ch}, value{val} {}

  Token(char ch, string s) : kind{ch}, name{s} {}
};

class Token_stream  // Поток ввода токенов
{
  bool full{false};
  Token buffer{'\0'};

public:
  Token_stream() {}

  Token get ();
  void putback (Token t);

  void ignore (char);
};

extern Token_stream ts;
#endif