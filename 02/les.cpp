#include <bits/stdc++.h>
using namespace std;

struct Point
{
  double x,y;
  Point() = default;
  Point(double xx, double yy): x{xx}, y{yy}{
  }
};
istream& operator>> (istream& in, Point& p){
  return in >> p.x >> p.y;
}
int main ()
{
  double x, y;
  vector<Point> values;
  Point p;
  while (cin >> p)
  {
    values.push_back(p);
  }
  double sx = 0.0, sx2 = 0.0, sy = 0.0, sxy = 0.0;
  int n = values.size();
  for (int i = 0; i < n; i++)
  {
    sx += values[i].x;
    sx2 += values[i].x * values[i].y;
    sy += values[i].y;
    sxy += values[i].x * values[i].y;
  }
  sx /= n;
  sx2 /= n;
  sy /= n;
  sxy /= n;
  double b = (sxy - sx * sy) / (sx2 - sx * sx);
  double a = sy - b*sx;
  cout << a << " " << b << endl;
}
