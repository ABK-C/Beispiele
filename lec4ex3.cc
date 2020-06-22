#include <list>
#include <iostream>
#include <algorithm>
#include <string>

int main() {
  using namespace std;
  //list<string> s;
  //s.push_back("Birne");
  //s.push_back("Apfel");
  //s.push_back("Kirsche");
  // oder in C++11
  list<string> s = {"Birne", "Apfel", "Kirsche"};

  list<string>::iterator i = find(s.begin(), s.end(), "Apfel");
  if (i != s.end()) {
    std::cout << "gefunden:" << *i << std::endl;
  }
  s.sort();
  for(auto a : s) {
    std::cout << a << std::endl;
  }
  list<string>::iterator j = min_element(s.begin(), s.end());
  std::cout << "kleinster Eintrag:" << *j << std::endl;

  int x = 5, y = 9;
  int m = max(x, y);
  std::cout << "max = " << m << std::endl;
}