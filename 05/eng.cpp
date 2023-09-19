#include "../lib1/std_lib_facilities.h"

vector<string> noun_items{"C++", "fish", "birds"};
vector<string> verb_items{"fly", "swim", "rules"};
vector<string> construction_items{"and", "but", "or"};

bool contains (const vector<string>& items, const string& val)
{
  for (auto x : items)
  {
    if (x == val)
      return true;
  }
  return false;
}

bool sentence ()
{
  string word;
  cin >> word;
  if (!cin || !contains(noun_items, word))
  {
    return false;
  }
  cin >> word;
  if (!cin || !contains(verb_items, word))
  {
    return false;
  }
  cin >> word;
  if (word == ".")
  {
    return true;
  }
  if (!cin || !contains(construction_items, word))
  {
    return false;
  }
  return sentence();
}

int main ()
{
  while (cin)
  {
    bool ok = sentence();
    cout << (ok ? "OK" : "Not OK") << endl;
  }
}