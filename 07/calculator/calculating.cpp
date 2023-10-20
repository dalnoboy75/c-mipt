#include "const.h"
#include "calculating.h"
#include "variable.h"
#include "token.h"
double primary ()  // вычисление первичного значения
{
  Token t = ts.get();
  switch (t.kind)
  {
  case '(':
  {
    double d = expression();
    t = ts.get();
    if (t.kind != ')')
      error("')' expected");
    return d;
  }

  case '-':
    return -primary();
  case '+':
    return +primary();

  case number:
    return t.value;

  case name:
    return st.get(t.name);

  default:
    error("primary expected");
  }
}

double underterm ()
{  // вычисление подтерма
  double left = primary();
  while (true)
  {
    Token t = ts.get();

    switch (t.kind)
    {
    case '^':
    {
      double s = primary();
      if (left == 0 && s < 0)
        error("zero in negative power");
      if (left < 0 && s == 0.5)
        error("negative number under root");
      left = pow(left, s);
      break;
    }

    default:
      ts.putback(t);
      return left;
    }
  }
}

double term ()  // вычисление терма
{
  double left = underterm();

  while (true)
  {
    Token t = ts.get();

    switch (t.kind)
    {
    case '*':
      left *= underterm();
      break;

    case '/':
    {
      double d = underterm();
      if (d == 0)
        error("divide by zero");
      left /= d;
      break;
    }
    case '%':
    {
      double d = underterm();
      if (d == 0)
        error("divide by zero");
      left = fmod(left, d);
      break;
    }
    default:
      ts.putback(t);
      return left;
    }
  }
}

double expression ()  // вычисление выражения
{
  double left = term();

  while (true)
  {
    Token t = ts.get();

    switch (t.kind)
    {
    case '+':
      left += term();
      break;

    case '-':
      left -= term();
      break;

    default:
      ts.putback(t);
      return left;
    }
  }
}

double declaration (bool c)  // создание переменной
{
  Token t = ts.get();
  if (t.kind != name)
    error("name expected in declaration");

  string var = t.name;
  if (st.is_declared(var))
  {
    error("declared twice");
  }

  t = ts.get();
  if (t.kind != '=')
    error("'=' missing in declaration of ", var);

  return st.define(var, expression(), c);
}

double change_value (Token t) // изменение переменной
{
  if (t.kind != name)
    error("name expected in declaration");

  string var = t.name;
  char c = ' ';
  while (c == ' ')
  {
    cin.get(c);
  }
  if (c != '=')
  {
    cin.putback(c);
    ts.putback(t);
    return expression();
  }
  cin.putback(c);
  if (!st.is_declared(var))
    error("not declared");
  if (st.check_const(var))
  {
    error("const cannot change");
  }
  t = ts.get();

  return st.set(var, expression());
}

double statement ()  // обработка типа инструкции
{
  Token t = ts.get();
  switch (t.kind)
  {
  case let:
    return declaration(false);
  case cons:
    return declaration(true);
  case name:
    return change_value(t);
  default:
    ts.putback(t);
    return expression();
  }
}

void clean_up_mess () { ts.ignore(print); }  // очистка потока ввода

void user_help ()  // вывод информации о программе
{
  cout << "Калькулятор предназначен для выполнения различных операций:\n\n";
  cout << "Простые арифметические операции: +, -, *, /,^ \n\n";
  cout << "Возможность создания переменных и констант с помощью слов let и "
          "const\n\n";
  cout << "Для того, чтобы воспользоваться калькулятором, введите "
          "выражение\n\n";
  cout << "Для получения результата, введите символ ';' или нажмите Enter "
          "\n\n ";
  cout << "Для выхода из программы введите  quit\n";
}

void calculate ()  // основное тело работы калькулятора
{
  cout << prompt;
  while (true)
    try
    {
      Token t = ts.get();

      while (t.kind == print || t.kind == enter_word)
      {
        if (t.kind == enter_word)
          cout << prompt;
        t = ts.get();
      }
      if (t.kind == quit)
        return;
      if (t.kind == help)
      {
        user_help();
      }
      else
      {
        ts.putback(t);
        cout << result << statement() << endl;
      }
    }
    catch (runtime_error& e)
    {
      cerr << e.what() << endl;
      clean_up_mess();
      cout << prompt;
    }
}
