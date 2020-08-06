#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <string_view>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
      map<int, unordered_set<string_view>> dicts;
      for (string &w : wordDict) 
        dicts[w.length()].insert(w);

      int n = s.size();
      string_view sv{s.c_str(), n};
      vector<vector<string>> memo(n);
      for (int i=n-1; i>=0; --i) {
        for (auto iter = dicts.begin(); iter!=dicts.end(); ++iter) {
          int len = iter->first;
          if (i+len>n) continue;
          if (iter->second.find(sv.substr(i, len))!=iter->second.end()) {
            string l = string(sv, i, len);
            if (i+len==n)
              memo[i].push_back(l);
            else {
              l += ' ';
              for (string &r : memo[i+len]) 
                memo[i].push_back(l + r);
            }
          }
        }
      }
      return memo[0];
    }
};

int main() {
  string s = "pineapplepenapple";
  vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
  Solution sol;
  vector<string> res = sol.wordBreak(s, wordDict);
  copy(res.begin(), res.end(), ostream_iterator<string>(cout, " "));
  return 0;
}