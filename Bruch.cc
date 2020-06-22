#include "Bruch.hh"

Bruch::Bruch(const Bruch& a) {
  std::cout << "Copyconstructor " << a.zaehler_ << ", " << a.nenner_ << std::endl;
  zaehler_ = a.zaehler_;
  nenner_ = a.nenner_;
}

Bruch::Bruch(int zaehler, int nenner) : zaehler_(zaehler), nenner_(nenner) {
  std::cout << " mein Konstruktor" << std::endl;
  kuerze();
}

Bruch::~Bruch() {
  std::cout << "destructor" << std::endl;
}

void Bruch::kuerze() {
  int ggt = ggT(zaehler_, nenner_);
  zaehler_ /= ggt;
  nenner_ /= ggt;
}

int Bruch::ggT(int a, int b) {
  if (b == 0)
    return a;
  return ggT(b, a % b);
}


Bruch Bruch::operator+(const Bruch& b) const {
  Bruch c(zaehler() * b.nenner() + b.zaehler() * nenner(), nenner() * b.nenner());
  return c;
}

std::ostream& operator<<(std::ostream& os, Bruch b) { return os << b.zaehler() << '/' << b.nenner();
}

std::istream& operator>>(std::istream& is,Bruch& b) {
  int z, n;
  is >> z >> n;
  b.zaehler_ = z;
  b.nenner_ = n;
  b.kuerze();
  return is;
}
