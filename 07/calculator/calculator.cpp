/*
Простой калькулятор

Ввод осуществляется из потока cin; вывод - в поток cout.

Грамматика для ввода:
Вычисление:
  Инструкция
  Вывод
  Выход
  Вычисление Инструкция
Инструкция:
  Объявпение
  Выражение
Объявление :
  "let" Имя "=" Выражение
Инструкция:
  Выражение
  Вывод
  Выход
Вывод:
  ; 
  \n
Выход:
  quit
Выражение :
  Терм
  Выражение + Терм
  Выражение - Терм

Терм:
  Подтерм
  Терм * Подтерм
  Терм / Подтерм
  Терм % Подтерм
  Терм
Подтерм:
  Первичное выражение
  Подтерм ^ первичное выражение
Первичное_выражение :
  Число
  ( Выражение )
  - Первичное_выражение
  + Первичное_выражение
Число :
  Литерал_с_плавающей_точкой

Ввод из потока cin через Token stream с именем ts.
*/

#include "calculating.h"
#include "const.h"
#include "token.h"
#include "variable.h"
int main ()
try
{
  st.define("pi", 3.141592653589793, true);
  st.define("e", 2.718281828459045, true);
  calculate();
}
catch (exception& e)
{
  cerr << "exception: " << e.what() << endl;
  return 1;
}
catch (...)
{
  cerr << "Oops, unknown exception" << endl;
  return 2;
}
