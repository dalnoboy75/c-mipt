#include "../lib1/std_lib_facilities.h"
#include <bits/stdc++.h>
using namespace std;

vector<char> gen_solution () { return {'1', '2', '3', '4'}; }

int count (const vector<char>& v, char d)
{
  int k = 0;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == d)
      k++;
  }
  return k;
}

vector<char> get_player_guess ()
{
  vector<char> guess(4);
  for (int i = 0; i < 4; i++)
  {
    cin >> guess[i];
  }
  if (!cin)
    error("invalid input");
  return guess;
}

tuple<int, int> calc_bulls_and_cows (vector<char> guess,
                                     vector<char> solution)
{
  int bulls = 0, cows = 0;
  for (int i = 0; i < 4; i++)
  {
    if (guess[i] == solution[i])
      bulls++;
    else if (count(solution, guess[i]) == 1)
      cows++;
  }
  return {bulls, cows};
}

int main ()
{
  try
  {
    vector<char> solution = gen_solution();
    cout << "The game 'Bulls and Cows' has started" << endl;
    bool game_is_running = true;
    while (game_is_running)
    {
      cout << "Guess the number: \n";
      vector<char> guess = get_player_guess();
      auto [bulls, cows] = calc_bulls_and_cows(guess, solution);
      if (bulls == 4)
      {
        game_is_running = false;
        cout << "you win \n";
      }
      else
        cout << "bulls: " << bulls << " cows: " << cows << endl;
    }
  }
  catch (exception& e)
  {
    cout << e.what() << endl;
  }
}