#include <iostream>

class A {
public:
  int f(int x) { return x + 1; }
};

class B : public A {
public:
  int f(int x) { return A::f(x * x); }
  int g(int x) { return f(x * x * x); }
};

int main() {
  A obj_a;
  B obj_b;
  A *obj_bp = new B();
  std::cout << obj_a.f(5) << std::endl;
  std::cout << obj_b.f(5) << std::endl;
  std::cout << obj_b.g(5) << std::endl;
  std::cout << obj_bp->f(5) << std::endl;
  return 0;
}