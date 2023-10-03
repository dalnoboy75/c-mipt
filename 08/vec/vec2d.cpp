#include "vec2d.h"
#include <cmath>
using namespace std;

Vec2D& Vec2D::operator+= (const Vec2D& rhs)
{
  x += rhs.x;
  y += rhs.y;
  return *this;
}

Vec2D& Vec2D::operator-= (const Vec2D& rhs)
{
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}

Vec2D& Vec2D::operator*= (double rhs)
{
  x *= rhs;
  y *= rhs;
  return *this;
}

Vec2D operator+ (const Vec2D& lhs, const Vec2D& rhs)
{
  return Vec2D{lhs} += rhs;
}

Vec2D operator- (const Vec2D& lhs, const Vec2D& rhs)
{
  return Vec2D{lhs} -= rhs;
}

Vec2D operator* (const Vec2D& lhs, double rhs) { return Vec2D{lhs} *= rhs; }

double length (const Vec2D& v) { return sqrt(v.x * v.x + v.y * v.y); }