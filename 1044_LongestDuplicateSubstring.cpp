#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

size_t hash_func(string& s) {
  size_t seed = 0;
  for (char c : s) {
    seed ^= c + 0x9e3779b9 + (seed<<6) + (seed>>2);
  }
  return seed;
}

class Solution {
  public:
    string longestDupSubstring(string S) {
      // TLE
      // plz simply use unordered_set ...
      unordered_map<size_t, vector<string>> hash_map;
      int n = S.size(), l = 2, r = n, m;
      string res = "";
      while (l<r) {
        hash_map.clear();
        m = l + (r-l)/2;

        bool flag=false;
        for (int i=0; i+m<=n; ++i) {
          string ss = S.substr(i, m);
          size_t hash_val = hash_func(ss);
          auto iter = hash_map.find(hash_val);
          if (iter!=hash_map.end()) {
            auto& vec = iter->second;
            if (find(vec.begin(), vec.end(), ss)!=vec.end()) {
              if (m>res.size()) res = ss;
              flag = true;
              break;
            }
            else
              vec.push_back(ss);
          }
          else {
            hash_map.insert(make_pair(hash_val, vector<string>{ss}));
          }
        }

        if (flag)
          l = m+1;
        else
          r = m;
      }
      return res;
    }
};

int main() {
  Solution sol;
  cout << sol.longestDupSubstring("banana") << endl;
  // cout << sol.longestDupSubstring("aaaaa") << endl;
  return 0;
}