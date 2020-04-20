#include <iostream>
#include <fstream>

double expx(double x) {
    double res = 1;
    double summand = 1;
    for(int n = 1 ; n < 100 ; n++) {
        if(n > 3) {
            continue;
        } else {
            summand *= x / n;
            res += summand;
        }
    }
    return res;
}

int main() {
  double x,y;
  std::cin >> x >> y;
  std::cout << "exp(" << x << ") = " << expx(x) << std::endl;
  std::cout << "exp(" << y << ") = " << expx(y) << std::endl;
  std::ofstream fout("out.txt");
  fout << x << " " << expx(x) << std::endl;
  fout << y << " " << expx(y) << std::endl;
  fout.close();
  std::ifstream fin("out.txt");
  for(int i = 0 ; i < 2 ; i++) {
      double nx, nexpx;
      fin >> nx >> nexpx;
      std::cout << "exp(" << nx << ") = " << nexpx << std::endl;
  }
  fin.close();
}