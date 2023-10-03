#include "../../lib1/std_lib_facilities.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vec2d.h>
#include <vector>
using namespace std;

#define EXPR(x) #x, x

struct TestV
{
  string expr;
  Vec2d result;
  Vec2d answer;
};

bool operator== (const Vec2D& p, const Vec2D& q)
{
  return p.x == q.x && p.y == q.y;
}

bool operator!= (const Vec2D& p, const Vec2D& q) { return !(p == q); }

Vec2d t{1, 1};
if (t.x != 1 && t.y != 1)
  throw std::runtime_error{"Failed to construct a valid Vec2d object"};
Vec2d r{1, 0}, q{0, 1};
Vec2d s{r}, p{q};
if (r != r || r == q || r == t)
  throw std::runtime_error{"Failed to compare Vec2d objects"};

vector<TestV> v_tests{
    {EXPR(r), {1, 0}},      {EXPR(q), {0, 1}},     {EXPR(r + r), {2, 0}},
    {EXPR(q + q), {0, 2}},  {EXPR(r + q), t},      {EXPR(r += r), {2, 0}},
    {EXPR(q += q), {0, 2}}, {EXPR(r), {2, 0}},     {EXPR(q), {0, 2}},
    {EXPR(r - s), {1, 0}},  {EXPR(q - p), {0, 1}}, {EXPR(r -= s), {1, 0}},
    {EXPR(q -= p), {0, 1}}, {EXPR(r), {1, 0}},     {EXPR(q), {0, 1}},
    {EXPR(r * 5), {5, 0}},  {EXPR(q * 5), {0, 5}}, {EXPR(5 * r), r * 5},
    {EXPR(5 * q), q * 5},   {EXPR(r = s), s},      {EXPR(q = p), p},
    {EXPR(r *= 5), s * 5},  {EXPR(q *= 5), p * 5}, {EXPR(r), s * 5},
    {EXPR(q), p * 5}};

int main ()
{
  int total = 0, passed = 0;
  for (const auto& [expr, res, ans] : v_tests)
  {
    bool ok = (res == ans);
    std::cerr << std::setw(10) << std::left << expr << " = {" << res.x
              << ", " << res.y << "}"
              << " [" << (ok ? "OK" : "FAILED") << "]" << std::endl;
    total++;
    if (ok)
      passed++;
  }
  std::cerr << "-----------\n"
            << passed << " passed of " << total << " total" << std::endl;
}