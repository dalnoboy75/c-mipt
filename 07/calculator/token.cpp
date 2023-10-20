#include "const.h"
#include "token.h"


void Token_stream::putback(Token t)  // Возвращаем токен обратно в поток
{
  if (full)
    error("putback() into a full buffer");

  buffer = t;
  full = true;
}

Token Token_stream::get()  // Считываем из консоли в поток токенов
{
  if (full)
  {
    full = false;
    return buffer;
  }

  char ch;
  cin.get(ch);
  while (cin && ch == ' ')
    cin.get(ch);
  if (!cin)
    return Token{quit};
  switch (ch)
  {
  case '(':
  case ')':
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case '^':
  case ';':
  case '=':
  case enter_word:
    return Token{ch};

  case '.':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  {
    cin.putback(ch);
    double val;
    cin >> val;
    return Token{number, val};
  }

  default:
    if (isalpha(ch))
    {
      string s;
      s += ch;
      while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
        s += ch;
      cin.putback(ch);

      if (s == declkey)
        return Token{let};
      if (s == constkey)
        return Token{cons};
      if (s == helpkey)
        return Token{help};
      if (s == quitkey)
        return Token{quit};
      return Token{name, s};
    }
    error("Bad token");
  }
}

void Token_stream::ignore(char c)  // игнорируем символы после ошибки до
                                   // ввода ";" или символа переноса строки
{
  if (full && c == buffer.kind)
  {
    full = false;
    return;
  }
  if (buffer.kind == enter_word)
    return;
  full = false;
  char ch;
  while (cin.get(ch))
    if (ch == c || ch == enter_word)
      return;
}

Token_stream ts;