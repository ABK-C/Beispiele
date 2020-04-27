#include <iostream>

int bla() {
  static int a = 1;
  ++a;
  return a;
}

int main() {
  for(int a = bla() ; a < 10 ; a = bla()) {
    if(a == 3) {
      break;
    } 
    std::cout << a << std::endl;
  }
}