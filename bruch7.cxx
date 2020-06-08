#include <iostream>


class Bruch {
public:
  Bruch(int z, int n);
  Bruch(const Bruch& b);
  Bruch(int z = 0) : m_z(z),m_n(1),m_r(z) {}
  
  int zaehler() const {return m_z;}
  int nenner() const {return m_n;}
  double r() const { return (m_r == 0) ? m_r = m_z/(double)m_n : m_r;}

  
  //Bruch operator+(const Bruch& b);
  Bruch& operator+=(const Bruch& b);
  operator double() { return r();}
  Bruch& operator++() { m_z+=m_n; return *this;}//prefix
  Bruch operator++(int) { m_z +=m_n ; return *this;}//postfix
  int operator[](int i) { return (i == 1) ? m_n : m_z;}
  int operator()(unsigned int i) { return (*this)[i-1];}

  friend std::istream& operator>>(std::istream&, Bruch&);

private:
  int m_z;
  int m_n;
  mutable double m_r;
  
  void kuerze();
  static int ggT(int a, int b);
};

//default argumente nicht wiederholen
Bruch::Bruch(int z, int n) : m_z(z), m_n(n),m_r(0)
{
  kuerze();
}

Bruch::Bruch(const Bruch& b) :m_z(b.m_z), m_n(b.m_n),m_r(0) {
  std::cout << "copy constructor called \n";
}

int Bruch::ggT(int a, int b) {
  if(b == 0) return a;
  return ggT(b, a % b);
}   

void Bruch::kuerze() {
  int teiler = ggT(m_z,m_n);
  if(teiler == 0) return;
  m_z /= teiler;
  m_n /= teiler;
};  

//Bruch Bruch::operator+(const Bruch& b) { 
//  std::cout << "einstellig\n";
// return Bruch(m_z * b.m_n + m_n * b.m_z,m_n * b.m_n);
//}

Bruch& Bruch::operator+=(const Bruch& b) {
  m_z = m_z * b.m_n + m_n * b.m_z;
  m_n *= b.m_n;
  kuerze();
  return *this;
}

Bruch operator+(const Bruch& a, const Bruch& b) {
  std::cout << "zweistellig\n";
//Bruch addiere(Bruch a, Bruch b) {
//Bruch addiere(const Bruch& a, const Bruch& b) {
  Bruch c = a;
  return c+= b;
}


std::ostream& operator<<(std::ostream& os, const Bruch& b) {
  return os << b.zaehler() << '/' << b.nenner();
}

std::istream& operator>>(std::istream& is,Bruch& b) {
  is >> b.m_z >> b.m_n;
  b.kuerze();
  return is;
}


int main()
{
  Bruch b1,b2;
  std::cin >> b1;
  std::cin >> b2;

  
  Bruch erg = b1 + b2;
  std::cout << erg.zaehler() << "/" << erg.nenner() << '\n';
  Bruch erg2 = b1 += b2;
  std::cout << erg2(1) << "/" << erg2(2) << '\n';
  std::cout << "real:" << erg2.r() << '\n';
  std::cout << "Bruch:" << erg2 << '\n';
  Bruch b4 = 3;
  std::cout << (++b4 + b2).r() << '\n';


  Bruch* a = new Bruch(1,2);
  Bruch* b = new Bruch(1,3);

  std::cout << *a << std::endl;

  double r = a->r();
  a->operator++();//++(*a)
  Bruch* c = &(*a + *b);

  delete a;
  delete b;
}
