#include "variable.h"

bool Symbol_table::check_const (string s) //проверка на то является ли переменная константой
  {
    for (int i = 0; i < int(var_table.size()); ++i)
      if (var_table[i].name == s)
        return var_table[i].is_const;

    error("get: undefined name ", s);
  }


double Symbol_table::get(string s)  // получаем значение переменной
{
  for (int i = 0; i < int(var_table.size()); ++i)
    if (var_table[i].name == s)
      return var_table[i].value;

  error("get: undefined name ", s);
}

double Symbol_table::set(string s,
                  double d)  // задаём значение существующей переменной
{
  for (int i = 0; i <= int(var_table.size()); ++i)
  {
    if (var_table[i].name == s)
    {
      if (var_table[i].is_const)
        error("const cannot change");
      var_table[i].value = d;
      return d;
    }
  }

  error("set: undefined name ", s);
}

bool Symbol_table::is_declared(
    string s)  // проверяем, существует ли такая переменная
{
  for (int i = 0; i < int(var_table.size()); ++i)
    if (var_table[i].name == s)
      return true;

  return false;
}

double Symbol_table::define(
    string var, double val,
    bool c)  // объявляем новую переменную, если такой ещё нет
{
  if (is_declared(var))
    error(var, " declared twice");

  var_table.push_back(Variable{var, val, c});

  return val;
}
Symbol_table st;