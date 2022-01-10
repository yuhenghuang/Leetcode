#include <unordered_set>
#include <local_leetcode.hpp>

class Solution {
  public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
      map<int, unordered_set<string_view>> dicts;
      for (string &w : wordDict) 
        dicts[w.length()].insert(w);

      int n = s.size();
      // s -> string view 'cause the substring of sv is string view
      string_view sv(s.c_str(), n);
      vector<vector<string>> memo(n);
      for (int i = n-1; i >= 0; --i) {
        for (auto iter = dicts.begin(); iter!=dicts.end(); ++iter) {
          int len = iter->first; // length of current words
          // early stop
          if (i + len > n) break;

          if (iter->second.find(sv.substr(i, len)) != iter->second.end()) {
            string l(sv, i, len);
            if (i+len == n) // right most word
              memo[i].push_back(l);
            else {
              l.push_back(' ');
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
  /*
  string s = "pineapplepenapple";
  vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
  Solution sol;
  vector<string> res = sol.wordBreak(s, wordDict);
  copy(res.begin(), res.end(), ostream_iterator<string>(cout, " "));
  */

  EXECS(Solution::wordBreak);
  return 0;
}