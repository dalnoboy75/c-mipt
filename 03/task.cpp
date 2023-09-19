#include <bits/stdc++.h>
using namespace std;

double pov (double x, int n)
{
  double res = 1;
  if (x == 0)
  {
    if (n == 0)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  if (n == 0)
  {
    return 1;
  }
  if (n < 0)
  {
    x = 1.0 / x;
    n = -n;
  }
  for (int i = 0; i < n; i++)
  {
    res *= x;
  }
  return res;
}

double pov_r (double x, int n)
{
  if (n < 0)
  {
    n = -n;
    x = 1.0 / x;
  }
  if (n == 0)
    return 1;
  return x * pov_r(x, n - 1);
}

void test_pov (double x, double tol)
{
  for (auto n : {0, -1, 1, 2, -2, -5, 5})
  {
    cout << "x = " << x << ", "
         << "n = " << n << ": " << endl;
    double etalon = pow(x, n);
    cout << "pow " << etalon << endl;
    using Func = double (*)(double, int);
#define FUN_NAME(function) make_pair(Func(function), string(#function))
    auto powers = {FUN_NAME(pov), FUN_NAME(pov_r)};
#undef FUN_NAME
    for (auto [f, name] : powers)
    {
      cout << setw(8) << left << name << " " << flush;
      double p = f(x, n);
      double diff = p - etalon;
      cout << p << " (difference is " << diff << ") ["
           << (abs(diff) < tol ? "OK" : "FAILED") << "]" << endl;
    }
  }
  cout << "\n";
}

int main ()
{
  constexpr double x = 1.3567;
  constexpr double tol = numeric_limits<double>::epsilon();
  test_pov(x, tol);
}