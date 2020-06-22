#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  vector<string> v;
  std::string s;
  getline(std::cin, s);
  while (s.length()) {
    v.push_back(s);
    getline(std::cin, s);
  };
  // count characters
  std::map<char, int> m;
  for (unsigned int i = 0 ; i < v.size() ; ++i) {
    std::cout << i << ":" << v[i] << std::endl;
    for (int j = 0; j < v[i].length(); ++j) {
      char c = tolower(v[i][j]);
      m[c]++;
    }
  }
  for (auto kv : m) {
    std::cout << kv.first << ": " << kv.second << '\n';
  }
}
