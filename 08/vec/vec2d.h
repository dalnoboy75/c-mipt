class Vec2D
{
public:
  Vec2D(double xx, double yy) : x{xx}, y{yy} {}

  Vec2D() = default;
  double x = 0, y = 0;

  Vec2D& operator+= (const Vec2D& rhs);
  Vec2D& operator-= (const Vec2D& rhs);
  Vec2D& operator*= (double rhs);
};

Vec2D operator- (const Vec2D& lhs, const Vec2D& rhs);
Vec2D operator* (const Vec2D& lhs, double rhs);
Vec2D operator+ (const Vec2D& lhs, const Vec2D& rhs);
double length (const Vec2D& v);