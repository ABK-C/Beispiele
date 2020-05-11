#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cctype>


struct CompareLength { 
  bool operator()(const std::string& s1, const std::string& s2) {
    return s1.length() < s2.length();
  }
};

using namespace std;

int main() 
{
  vector<string> v;
  string s;
  getline(cin,s);
  while(s.length()) {
    v.push_back(s);
    getline(cin,s);
  };
  //sort(v.begin(),v.end());
  //sort(v.begin(),v.end(),CompareLength());
  sort(v.begin(), v.end(), [] (const string& s1, const string& s2) {
      return s1.length() < s2.length();
  });

  for(string s : v) {
    cout << s << '\n';
  }
  //count char
  map<char,int> m;
  for(auto s : v) {
    for(int j = 0 ; j < s.length() ; ++j) {
      char c = tolower(s[j]); 
      m[c]++;
    }
  }
  for(auto i : m) {
    cout << i.first << ": " << i.second << '\n';
  }
}
