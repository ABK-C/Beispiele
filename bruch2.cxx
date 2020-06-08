#include <iostream>

int ggT(int a, int b);

struct Bruch {
  int zaehler;
  int nenner;
  /*
  Bruch(int z, int n) {
    zaehler = z;
    nenner = n;
  }
  Bruch() {
    zaehler = 0;
    nenner = 0;
  }
  */
  Bruch(int z = 0, int n = 0) : zaehler(z),nenner(n) {};
  void kuerze() {
    int teiler = ggT(zaehler,nenner);
    zaehler /= teiler;
    nenner  /= teiler;
  }
};

int ggT(int a, int b) {
  if(b == 0) return a;
  return ggT(b, a % b);
} 

Bruch addiere(Bruch a, Bruch b) {
  Bruch erg(a.zaehler * b.nenner + b.zaehler * a.nenner,a.nenner * b.nenner);
  erg.kuerze();
  return erg;
}

int main()
{
  Bruch b1,b2;
  std::cin >> b1.zaehler >> b1.nenner;
  std::cin >> b2.zaehler >> b2.nenner;
  
  Bruch erg = addiere(b1,b2);
  std::cout << erg.zaehler << "/" << erg.nenner << '\n';
}
