#include <iostream>
#include <fstream>

double expo(double x) {
  double summand = 1;
  double expx = 0;
  for(int i = 0 ; i < 4 ; ++i) {
    expx += summand;
    summand *= x/(i+1);
  }
  return expx;
}

int main() {
  double x;
  std::cin >> x;
  std::cout << "exp(" << x << ") = " << expo(x) << std::endl;
  //std::ofstream fout("text.txt");
  //fout << x << " " << expo(x) << std::endl;
  //fout.close();
  std::ifstream fin("text.txt");
  double d;
  fin >> d;
  std::cout << d << std::endl;
  fin >> d;
  std::cout << d << std::endl;
}