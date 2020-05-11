#include <iostream>

int f(int a, int &b, const int c, const int &d) {
  std::cout << a << " " << b << " " << c << " " << d << std::endl;
  ++a;
  ++b;
  ++c;
  ++d;
  std::cout << a << " " << b << " " << c << " " << d << std::endl;
}

int main() {
  int w = 0, x = 0, y = 0, z = 0;
  f(w, x, y, z);
  std::cout << w << " " << x << " " << y << " " << z << std::endl;
}
