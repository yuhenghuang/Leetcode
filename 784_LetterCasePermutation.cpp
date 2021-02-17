#include "utils2.hpp"

class Solution {
  private:
    void dfs(string& tmp, const string& s, vector<string>& res) {
      if (tmp.size() == s.size()) {
        res.push_back(tmp);
        return;
      }

      char c = s[tmp.size()];
      tmp.push_back(c);
      dfs(tmp, s, res);
      tmp.pop_back();

      if (isalpha(c)) {
        tmp.push_back(c >= 'a' ? (c - 32) : (c + 32));
        dfs(tmp, s, res);
        tmp.pop_back();
      }
    }

  public:
    vector<string> letterCasePermutation(string S) {
      string tmp;
      vector<string> res;

      dfs(tmp, S, res);
      return res;
    }
};


int main() {
  UFUNC(Solution::letterCasePermutation);
  return 0;
}