#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <vector>

int main() {
  std::vector<std::string> v;
  std::string s;
  getline(std::cin, s);
  while (s.length()) {
    v.push_back(s);
    getline(std::cin, s);
  };

  // count characters
  std::map<char, int> m;
  for (std::vector<std::string>::const_iterator i = v.begin(); i != v.end();
       ++i) {
    std::string s(*i);
    for (int j = 0; j < i->length(); ++j) {
      char c = tolower(s[j]);
      m[c]++;
    }
  }
  for (std::map<char, int>::const_iterator i = m.begin(); i != m.end(); ++i) {
    std::cout << i->first << ": " << i->second << '\n';
  }
}
