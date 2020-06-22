#include <iostream>
#include "Bruch.hh"

int main() {
  Bruch a, b;
  std::cin >> a >> b;
  Bruch c = a + b; 
  std::cout << c << '\n';
}
