#include "../lib1/std_lib_facilities.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>
using namespace std;

bool check_game (vector<int>& num);
void bot (vector<int>& num);
vector<int> check_ans (string ans);
void player (vector<int>& num);
void game (vector<int>& num);

bool check_game (vector<int>& num)
{
  for (auto x : num)
  {
    if (x)
      return false;
  }
  return true;
}

void bot (vector<int>& num)
{
  bool fl = true;
  for (int i = 0; i < num.size(); i++)
  {
    if (num[i] > 0 && fl)
    {
      for (int j = 1; j <= num[i]; j++)
      {
        int hor = 0;
        for (int k = 0; k < num.size(); k++)
        {
          if (k == i)
            hor ^= num[i] - j;
          else
            hor ^= num[k];
        }
        if (hor == 0)
        {
          fl = false;
          num[i] -= j;
          cout << "Компьютер сделал ход\n";
          if (check_game(num))
          {
            cout << "Компьютер победил. Игра окончена\n";
            break;
          }
          else
          {
            game(num);
            player(num);
            break;
          }
        }
      }
    }
  }
  if (fl)
  {
    for (int i = 0; i < num.size(); i++)
    {
      if (num[i] > 0)
      {
        num[i] -= 1;
        cout << "Компьютер сделал ход \n";
        game(num);
        player(num);
        break;
      }
    }
  }
}

vector<int> check_ans (string ans)
{
  vector<int> checked;
  string n = "";
  for (int i = 0; i < ans.size(); i++)
  {
    if (isdigit(ans[i]))
    {
      n += ans[i];
    }
    if ((ans[i] == ' ' || i == (ans.size() - 1)) && n != "")
    {
      checked.push_back(stoi(n));
      n = "";
    }
    if (ans[i] != ' ' && !isdigit(ans[i]))
    {
      return {0};
    }
  }
  if (checked.size() > 2)
    return {0};

  return checked;
}

void player (vector<int>& num)
{
  cout << "Ваш ход. Введите номер ряда и количество фишек \n";
  string s;
  while (getline(cin, s))
  {
    if (!cin)
    {
      throw runtime_error("Конец игры");
      exit(0);
      break;
    }
    if (s.size() == 0)
    {
      cout << "Неправильный ввод, попробуйте снова\n";
      player(num);
      return;
    }
    vector<int> ans = check_ans(s);
    if (ans.size() == 1 || ans[0] < 1 || ans[0] > num.size() ||
        ans[1] < 1 || ans[1] > num[ans[0] - 1] || ans[0] > num.size())
    {
      cout << "Неправильный ввод, попробуйте снова\n";
      player(num);
      return;
    }
    else
    {
      num[ans[0] - 1] -= ans[1];
      cout << "Ход сделан" << endl;
      break;
    }
  }
  if (check_game(num))
  {
    cout << "Вы выиграли. Игра окончена\n";
  }
  else
  {
    game(num);
    bot(num);
  }
}

void game (vector<int>& num)
{
  for (int i = 0; i < num.size(); i++)
  {
    cout << i + 1 << " -";
    for (int j = 0; j < num[i]; j++)
    {
      cout << " * ";
    }
    cout << "\n";
  }
}

vector<int> made_num ()
{
  srand(time(nullptr));
  cout << "Введите количество рядов(не менее 3 и не более 7)" << endl;
  string s;
  while (getline(cin, s))
  {
    if (!cin)
    {
      throw runtime_error("Конец игры");
      exit(0);
      break;
    }
    if (s.size() == 0)
    {
      cout << "Неправильный ввод, попробуйте снова\n";
      return made_num();
    }
    vector<int> checked;
    string n = "";
    for (int i = 0; i < s.size(); i++)
    {
      if (isdigit(s[i]))
      {
        n += s[i];
      }
      if ((s[i] == ' ' || i == (s.size() - 1)) && n != "")
      {
        checked.push_back(stoi(n));
        n = "";
      }
      if (s[i] != ' ' && !isdigit(s[i]))
      {
        cout << "Неправильный ввод, попробуйте снова\n";
        return made_num();
      }
    }
    if (checked.size() > 1 || (checked[0] < 3 || checked[0] > 7))
    {
      cout << "Неправильный ввод, попробуйте снова\n";
      return made_num();
    }
    cout << "Размер принят" << endl;
    vector<int> res(checked[0]);
    for (int i = 0; i < res.size(); i++)
    {
      int r = rand() % 4 + 3;
      res[i] = r;
    }
    return res;
  }
  return{0};
}
int main ()
{
  try
  {
    cout << "Приветствуем вас в игре НИМ \nИгра начинается \n";
    vector<int> num = made_num();
    game(num);
    player(num);
  }
  catch (exception& e)
  {
    cout << e.what() << endl;
    return 123;
  }
}