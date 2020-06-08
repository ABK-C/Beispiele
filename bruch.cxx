#include <iostream>

struct Bruch {
  int zaehler;
  int nenner;
};

int ggT(int a, int b) {
  if(b == 0) return a;
  return ggT(b, a % b);
} 

Bruch kuerze(Bruch erg) {
  int teiler = ggT(erg.zaehler,erg.nenner);
  erg.zaehler /= teiler;
  erg.nenner  /= teiler;
  return erg;
}

Bruch addiere(Bruch a, Bruch b) {
  Bruch erg = {a.zaehler * b.nenner + b.zaehler * a.nenner,a.nenner * b.nenner};
  return kuerze(erg);
}

int main()
{
  Bruch b1,b2;
  std::cin >> b1.zaehler >> b1.nenner;
  std::cin >> b2.zaehler >> b2.nenner;
  
  Bruch erg = addiere(b1,b2);
  std::cout << erg.zaehler << "/" << erg.nenner << '\n';
}
