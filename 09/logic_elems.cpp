#include "../lib1/std_lib_facilities.h"
using namespace std;

enum class ElementType
{
  src, and_op, or_op;
};

class Element
{
public:
  bool Output ();
  ElementType type;
  Input Inputing;
};

struct Input{
  const Element& Previous;
  bool is_inverted;
}

int main(){
  
}
